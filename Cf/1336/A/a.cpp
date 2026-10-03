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
 
//c1 sub[c1]
//c2 sub[c1]-sub[u]
//c3 sub[c1]+sub[c2]-sub[u]
//ck sub[c1]+sub[c2]+sub[c{k-1}]-sub[u]
constexpr ll mxN=2e5+1;
ll n,k;
vc<ll> adj[mxN],a;
ll dfs(ll u=1,ll p=0,ll d=0){
	ll sub=1;
	for(auto &v:adj[u]){
		if(v==p) continue;
		sub+=dfs(v,u,d+1);
	}
	a.emp(d-sub+1);
	return sub;
}
void solve(){
	cin >> n >> k;
	forn(i,1,n){ll u,v; cin >> u >> v,adj[u].emp(v),adj[v].emp(u);}
	dfs();
	sort(all(a),[](ll x,ll y){return x>y;});
	ll res=0;
	forn(i,0,k) res+=a[i];
	cout << res << '\n';
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
