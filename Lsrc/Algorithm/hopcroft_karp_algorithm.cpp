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

constexpr ll mxN=1001;
ll n,m,k,mat[mxN]{},d[mxN];
vc<ll> adj[mxN];
bool bfs(){
	queue<ll> q;
	memset(d,-1,8*(n+m+1));
	forn(i,1,n+m+1) if(!mat[i]) q.emplace(i),d[i]=0;
	while(!q.empty()){
		ll u=q.front(); q.pop();
		if(~d[0]) break;
		for(auto&v:adj[u]){
			if(d[mat[v]]==-1) d[mat[v]]=d[u]+1,q.emplace(mat[v]);
		}
	}
	return ~d[0];
}
bool dfs(ll u){
	if(!u) return true;
	for(auto&v:adj[u]) if(d[mat[v]]==d[u]+1 && dfs(mat[v])){mat[u]=v,mat[v]=u; return true;}
	d[u]=inf;
	return false;
}
void hop_kar(){
	for(;bfs();){
		forn(i,1,n+m+1) if(!mat[i]) dfs(i);
	}
	vc<ar<ll,2>> res;
	forn(i,1,n+1) if(mat[i]) res.emp(ar<ll,2>{i,mat[i]-n});
	cout << res.size() << '\n';
	for(auto&[u,v]:res) cout << u << ' ' << v << '\n';
}
void solve(istream &cin){
	cin >> n >> m >> k;
	forn(i,0,k){
		ll u,v; cin >> u >> v,v+=n;
		adj[u].emp(v),adj[v].emp(u);
	}
	hop_kar();
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
