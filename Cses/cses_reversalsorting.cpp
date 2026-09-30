 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
using namespace std;
using ii=int;
// using ll=int;
using ll=long long;
using ull=unsigned long long;
#define DEBUG 1 
#if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
    template<typename T,typename... Args>
    inline void debug (const T& val,const Args&... args){
        cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
    }
    #define terr cerr << "I am here" << '\n'
#endif
#define fast_io cin.tie(0),ios_base::sync_with_stdio(false)
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define ps push
#define emp emplace_back
#define pb push_back
#define lwb lower_bound
#define upb upper_bound
#define vc vector
#define ar array
#define uno unordered_map
#define uns unordered_set
#define pr pair
#define pii pr<ii,ii>
#define pll pr<ll,ll>
#define prq priority_queue
#define mls multiset
#define rbg rbegin
#define bg begin
#define ed end
#define fr first
//#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=2e18;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
// char dir[4]={'L','D','R','U'};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

//1000000000949747713=2^29*3*73*8505229 c=3*73*8505229=1862645151
//root=5  max_len=2^29
// constexpr ll mod=1000000000949747713;
// constexpr ll root=944855867104044178;
// constexpr ll root_inv=190817968088312480;
// constexpr ll maX=1LL<<29;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const ll M = 991831889;
// const ll C = uniform_int_distribution<ll>(0.1 * M, 0.9 * M)(rng);


constexpr ll mxN=2e5+5;
ll n,t[mxN][2]{},val[mxN],f[mxN]{},sub[mxN],lz[mxN],id,rt,rval[mxN];
vc<ll> b;
ll dir(ll x){return x==t[f[x]][1];}
void push_up(ll x){sub[x]=sub[t[x][0]]+1+sub[t[x][1]];}
void rotate(ll x){
	ll y=f[x],z=f[y],d=dir(x);
	t[y][d]=t[x][d^1],t[x][d^1]=y;
	if(z) t[z][dir(y)]=x;
	if(t[y][d]) f[t[y][d]]=y;
	f[y]=x,f[x]=z;
	push_up(y),push_up(x);
}
void push_down(ll x){
	if(lz[x]){
		swap(t[x][0],t[x][1]);
		if(t[x][0]) lz[t[x][0]]^=1;
		if(t[x][1]) lz[t[x][1]]^=1;
		lz[x]=0;
	}
}
void push_all(ll w,ll x){
	if(x!=w){
		push_all(w,f[x]);
		push_down(x);
	}
}
void splay(ll &z,ll x){
	ll w=f[z];
	push_all(w,x);
	for(ll y;(y=f[x])!=w;rotate(x)){
		if(f[y]!=w) rotate(dir(x)==dir(y)?y:x);
	}
	z=x;
}

void loc(ll &z,ll k){
	ll x=z;
	for(push_down(x);sub[t[x][0]]+1!=k;push_down(x)){
		if(k<=sub[t[x][0]]) x=t[x][0];
		else k-=(sub[t[x][0]]+1),x=t[x][1];
	}
	splay(z,x);
}
void build(){
	forn(i,1,n+3){
		++id,t[id][0]=rt,val[id]=b[i],rval[b[i]]=id;
		if(rt) f[rt]=id;
		rt=id;
	}
	splay(rt,1);
}
void print(ll x){
	if(!x) return ;
	push_down(x);
	print(t[x][0]);
	cout << val[x] << ' ';
	print(t[x][1]);
}
void print(){
	loc(rt,1);
	loc(t[rt][1],sub[rt]-1);
	print(t[t[rt][1]][0]); cout << '\n';
}
void reverse(ll l,ll r){
	loc(rt,l);
	loc(t[rt][1],r-l+2);
	lz[t[t[rt][1]][0]]^=1;
	push_down(t[t[rt][1]][0]);
}
void solve(istream &cin){
	cin >> n;
	rt=id=0;
	b.resize(n+3,0);
	forn(i,2,n+2) cin >> b[i];
	build();
	vc<ar<ll,2>> res;
	forn(i,1,n+1){
		// print();
		loc(rt,i);
		loc(t[rt][1],1);
		//err(i,rt,t[rt][1],val[t[rt][1]]);
		if(val[t[rt][1]]!=i){
			splay(t[rt][1],rval[i]);
			//err(rval[i],t[rt][1],sub[rt],sub[t[t[rt][1]][1]]);
			res.emp(ar<ll,2>{i,sub[rt]-sub[t[t[rt][1]][1]]-1});
			reverse(i,sub[rt]-sub[t[t[rt][1]][1]]-1);
			// loc(t[t[rt][1]][1],1);
			// splay(t[rt][1],t[t[rt][1]][1]);
			// lz[t[t[rt][1]][0]]^=1;
		}
	}
	cout << res.size() << '\n';
	if(res.size()) for(auto &[u,v]:res) cout << u << ' ' << v << '\n';
}
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

