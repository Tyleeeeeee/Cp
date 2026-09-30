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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const ll M = 991831889;
// const ll C = uniform_int_distribution<ll>(0.1 * M, 0.9 * M)(rng);


constexpr ll mxN=123457;
ll n,m,a[mxN]{},aa=0,bb=0,sz[mxN];
vc<ll> adj[mxN];
ll bfs(ll st){
	ll x=0,y=inf;
	vc<ll> vs(n+1,0);
	queue<ar<ll,2>> qu;
	qu.emplace(ar<ll,2>{st,0}),vs[st]=1;
	while(!qu.empty()){
		auto [u,d]=qu.front(); qu.pop();
		if(a[u]){
			if(d>x || (x==d && u<y)) x=d,y=u;
		}
		for(auto&v:adj[u]) if(!vs[v]) qu.emplace(ar<ll,2>{v,d+1}),vs[v]=1;
	}
	return y;
}
void dfs(ll u,ll p=0,ll d=0){
	sz[u]=a[u];
	for(auto&v:adj[u]){
		if(v!=p){
			dfs(v,u,d+1);
			sz[u]+=sz[v];
			if(sz[v]) aa+=2;
		}
	}
	if(a[u]) bb=max(bb,d);
}
void solve(istream &cin){
	cin >> n >> m;
	forn(i,0,n-1){
		ll u,v; cin >> u >> v;
		adj[u].emp(v),adj[v].emp(u);
	}
	ll u,v;
	forn(i,0,m){ll x; cin >> x; a[x]=1; if(!i) u=x;}
	v=bfs(u);
	u=bfs(v);
	dfs(u);
	cout << min(u,v) << '\n' << aa-bb << '\n';
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
