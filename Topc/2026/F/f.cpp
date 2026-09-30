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
ll n,m,d[mxN];
vc<ar<ll,3>> adj[mxN];
void solve(){
	cin >> n >> m;
	fill(1+d,1+n+d,-inf);
	forn(i,1,m+1){
		ll u,v,t,h;
		cin >> u >> v >> t >> h;
		adj[u].emp(ar<ll,3>{v,t,h}),adj[v].emp(ar<ll,3>{u,t,h});
	}
	mls<ar<ll,2>> hp;
	hp.emplace(ar<ll,2>{d[1]=inf,1});
	while(!hp.empty()){
		auto [lat,u]=*(--hp.ed()); hp.erase(--hp.ed());
		if(lat>d[u]) continue;
		for(auto &[v,t,h]:adj[u]){
			if(min(d[u],h)-t>d[v]) hp.emplace(ar<ll,2>{d[v]=min(d[u],h)-t,v});
		}
	}
	forn(i,1,n+1) cout << (d[i]>=0?1:0); cout << '\n';
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
