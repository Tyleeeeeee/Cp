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
//1000000000949747713=2^29*3*73*8505229 c=3*73*8505229=1862645151
//root=5  max_len=2^29
// constexpr ll mod=1000000000949747713;
// constexpr ll root=944855867104044178;
// constexpr ll root_inv=190817968088312480;
// constexpr ll maX=1LL<<29;

constexpr ll mxN=2e5+1;
ll n,a[mxN],dp1[mxN],dp2[mxN],s[mxN],d[mxN],p[mxN];
vc<ll> adj[mxN];
void dfs(ll u=1,ll pp=0){
	ll b1,b2;
	s[u]=a[u],d[u]=b1=b2=0;
	for(auto&v:adj[u]){
		if(v!=pp){
			dfs(v,u),s[u]+=s[v],d[u]=max(d[u],d[v]+1),b2=max(b2,d[v]+1);
			if(b2>b1) swap(b1,b2);
			dp1[u]+=dp1[v]+s[v];
		}
	}
	for(auto&v:adj[u]){
		if(v!=pp){
			if(!b2) dp2[u]=dp2[v]+s[v];
			else dp2[u]=max({dp2[u],dp1[u]+(d[v]+1==b1?b2:b1)*s[v],dp1[u]-dp1[v]+dp2[v]});
		}
	}
}
void solve(istream &cin){
	cin >> n;
	memset(s,0,8*(n+1));
	memset(d,0,8*(n+1));
	memset(dp1,0,8*(n+1));
	memset(dp2,0,8*(n+1));
	forn(i,1,n+1) adj[i].clear();
	forn(i,1,n+1) cin >> a[i];
	if(n==1){cout << '0' << '\n';return;}
	forn(i,1,n){
		ll u,v; cin >> u >> v;
		adj[u].emp(v),adj[v].emp(u);
	}
	dfs();
	forn(i,1,n+1) cout << max(dp1[i],dp2[i]) << " \n"[i==n];
}
int main()
{
    fast_io;
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
