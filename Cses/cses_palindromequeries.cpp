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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll M = mdl1;
const ll C = uniform_int_distribution<ll>(0.1 * M, 0.9 * M)(rng);

class Node{
	public:
		ii len,lk,nxt[26];
};
//Node t[mxN];
// void sam(){
// 	ii cur,last=0;
// 	t[last].len=0,t[last].lk=-1,memset(t[last].nxt,0,sizeof(t[last].nxt));
// 	for(auto &v:s){
// 		ii c=v-'a',p,q;
// 		cur=++id,t[cur].len=t[last].len+1;
// 		for(p=last;~p && !t[p].nxt[c];t[p].nxt[c]=cur,p=t[p].lk);
// 		if(!~p) t[cur].lk=0;
// 		else{
// 			q=t[p].nxt[c];
// 			if(t[q].len==t[p].len+1) t[cur].lk=q;
// 			else{
// 				ll clone=++id;
// 				t[clone].len=t[p].len+1,t[clone].lk=t[q].lk,memcpy(t[clone].nxt,t[q].nxt,sizeof(t[q].nxt));
// 				for(;t[p].nxt[c]==q;t[p].nxt[c]=clone,p=t[p].lk);
// 				t[q].lk=t[cur].lk=clone;
// 			}
// 		}
// 		last=cur;
// 	}
// }
//L..i'...j...i..R
//i'=L+R-i

constexpr ll mxN=2e5+1;
ll n,m,t1[mxN<<2],t2[mxN<<2],c[mxN],invc[mxN];
string s,rs;
void build(ll *t,string &ref,ll i,ll sl,ll sr){
	ll mid=(sl+sr)>>1;
	if(sl==sr){t[i]=((ref[sl-1]-'a')*c[sl])%M; return ;}
	build(t,ref,i<<1,sl,mid),build(t,ref,i<<1|1,mid+1,sr);
	t[i]=(t[i<<1]+t[i<<1|1])%M;
}
void pst(ll *t,ll i,ll sl,ll sr,ll ta,ll val){
	ll mid=(sl+sr)>>1;
	if(sl==sr){t[i]=(val*c[sl])%M; return;}
	if(ta<=mid) pst(t,i<<1,sl,mid,ta,val);
	else pst(t,i<<1|1,mid+1,sr,ta,val);
	t[i]=(t[i<<1]+t[i<<1|1])%M;
}
ll query(ll *t,ll i,ll sl,ll sr,ll l,ll r){
	if(l>sr || r<sl) return 0;
	ll mid=(sl+sr)>>1;
	if(l<=sl && sr<=r) return t[i];
	return (query(t,i<<1,sl,mid,l,r)+query(t,i<<1|1,mid+1,sr,l,r))%M;
}
void solve(istream &cin){
	 cin >> n >> m >> s,rs=s;
	 reverse(all(rs));
	 build(t1,s,1,1,n),build(t2,rs,1,1,n);
	 for(ll op,x,y;m;m--){
		 cin >> op >> x;
		 char tmp;
		 if(op==2) cin >> y;
		 else cin >> tmp;
		 if(op==1) pst(t1,1,1,n,x,tmp-'a'),pst(t2,1,1,n,n-x+1,tmp-'a');
		 else{
			ll p,q;
			p=(query(t1,1,1,n,x,y)*invc[x])%M;
			q=(query(t2,1,1,n,n-y+1,n-x+1)*invc[n-y+1])%M;
			cout << (p==q?"YES":"NO") << '\n';
		 }
	 }
}
ll fsp(ll a,ll m){ll ans=1;for(;m;ans=(m&1?(ans*a)%M:ans),a=(a*a)%M,m>>=1); return ans;}
int main()
{
	c[1]=C,invc[1]=fsp(C,M-2);
	forn(i,2,mxN) c[i]=(c[i-1]*C)%M,invc[i]=(invc[i-1]*invc[1])%M;
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

