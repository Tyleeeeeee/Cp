 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
using namespace std;
using ii=int;
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
#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
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

class Node{
	public:
		ll m[2][2];
		Node(){}
		Node(ll a,ll b,ll c,ll d){m[0][0]=a,m[0][1]=b,m[1][0]=c,m[1][1]=d;}
		friend Node operator+(const Node &a,const Node &b){
			return {max(a.m[0][0],b.m[0][0]),min(a.m[0][1],b.m[0][1]),max(a.m[1][0],b.m[1][0]),min(a.m[1][1],b.m[1][1])};
		}
};
//00 max x+y
//01 min x+y
//10 max x-y
//11 min x-y
constexpr ll mxN=1e6;
ll n,m,p,res[mxN];
vc<ar<ll,3>> a,b;
vc<Node> t(mxN<<1);
void pst(ll p,ll v1,ll v2){for(t[p+=mxN-1]={v1,v1,v2,v2};p>>=1;t[p]=t[p<<1]+t[p<<1|1]);}
Node query(ll l,ll r){
	Node ans{-inf,inf,-inf,inf};
	for(l+=mxN-1,r+=mxN-1;l<=r;l>>=1,r>>=1){
		if(l&1) ans=ans+t[l++];
		if(r&1^1) ans=ans+t[r--];
	}
	return ans;
}
void solve(){
	cin >> n >> m;
	a.resize(n),b.resize(m);
	memset(res,0x3f,sizeof(res));
	for(ll i=0; auto &[u,v,id]:a) cin >> u >> v,id=i++;
	for(ll i=0; auto &[u,v,id]:b) cin >> u >> v,id=i++;
	forn(i,1,2*mxN) t[i]={-inf,inf,-inf,inf};
	sort(all(a)),sort(all(b));
	p=0;
	forn(i,0,m){
		auto [x,y,id]=b[i];
		for(;p<n && a[p][0]<=x;pst(a[p][1],a[p][0]+a[p][1],a[p][0]-a[p][1]),p++);
		if(ll k=query(1,y).m[0][0]; k>-inf) res[id]=min(res[id],x+y-k);
		if(ll k=query(y,mxN).m[1][0]; k>-inf) res[id]=min(res[id],x-y-k);
	}
	forn(i,1,2*mxN) t[i]={-inf,inf,-inf,inf};
	sort(all(a),[](auto a,auto b){return a[0]>b[0];});
	sort(all(b),[](auto a,auto b){return a[0]>b[0];});
	p=0;
	forn(i,0,m){
		auto [x,y,id]=b[i];
		for(;p<n && a[p][0]>=x;pst(a[p][1],a[p][0]+a[p][1],a[p][0]-a[p][1]),p++);
		if(ll k=query(y,mxN).m[0][1]; k<inf) res[id]=min(res[id],k-(x+y));
		if(ll k=query(1,y).m[1][1]; k<inf) res[id]=min(res[id],k-(x-y));
	}
	ll r=0;
	forn(i,0,m) cout << res[i] << " \n"[i==m-1];
}
int main()
{
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
