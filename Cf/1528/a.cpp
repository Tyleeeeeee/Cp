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
#define MAX(x,y) (x=max(x,y))
#define MIN(x,y) (x=min(x,y))
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=1e5+102;
ll n,l[mxN],r[mxN],dp[mxN][2];
vc<ll> adj[mxN];
void dfs(ll u=1,ll p=0){
	dp[u][0]=dp[u][1]=0;
	for(auto &v:adj[u]){
		if(v==p) continue;
		dfs(v,u);
		dp[u][0]+=max(abs(l[u]-l[v])+dp[v][0],abs(l[u]-r[v])+dp[v][1]);
		dp[u][1]+=max(abs(r[u]-l[v])+dp[v][0],abs(r[u]-r[v])+dp[v][1]);
	}
}
void solve(){
	cin >> n;
	forn(i,1,n+1) cin >> l[i] >> r[i],adj[i].clear();
	forn(i,1,n){ll u,v; cin >> u >> v,adj[u].emp(v),adj[v].emp(u);}
	dfs();
	cout << max(dp[1][0],dp[1][1]) << '\n';
}
int main()
{
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
