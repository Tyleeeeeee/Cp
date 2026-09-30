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
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=2501;
ll n,m,q,res[100001]{},d[mxN][2];
vc<ll> adj[mxN];
vc<ar<ll,3>> query[mxN];
void bfs(ll st){
	queue<ar<ll,2>> q;
	memset(d,0x3f,sizeof(d));
	q.emplace(ar<ll,2>{st,0}),d[st][0]=0;
	while(!q.empty()){
		auto [u,dis]=q.front(); q.pop();
		for(auto &v:adj[u]){
			if(dis+1<d[v][dis&1^1]) d[v][dis&1^1]=dis+1,q.emplace(ar<ll,2>{v,dis+1});
		}
	}
}

void solve(){
	cin >> n >> m >> q;
	forn(i,1,m+1){ll u,v; cin >> u >> v; adj[u].emp(v),adj[v].emp(u);}
	for(ll a,b,x,i=1;i<=q;i++){
		cin >> a >> b >> x;
		if(a>b) swap(a,b);
		//if(a==b) res[i]=(x&1^1);
		query[a].emp(ar<ll,3>{b,x,i});
	}
	forn(i,1,n+1){
		if(query[i].empty()) continue;
		bfs(i);
		for(auto &[v,x,ind]:query[i]) res[ind]=(d[v][x&1]<=x);
	}
	forn(i,1,q+1) cout << (res[i]?"YES":"NO") << '\n';
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
