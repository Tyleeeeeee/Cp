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

constexpr ll mxN=101;
ll n,mat[2*mxN]{},vs[2*mxN]{},vis[2*mxN];
string s[mxN];
vc<ll> adj[mxN];
ll dfs(ll u){
	if(vis[u]) return 0; vis[u]=1;
	for(auto &v:adj[u]){
		if(!mat[v] || dfs(mat[v])){
			mat[v]=u,mat[u]=v;
			return 1;
		}
	}
	return 0;
}
void run(ll u){
	vs[u]=1;
	for(auto &v:adj[u]){
		if(v!=mat[u]){
			vs[v]=1;
			if(!vs[mat[v]]) run(mat[v]);
		}
	}
}
void solve(istream &cin){
	cin >> n;
	forn(i,0,n) cin >> s[i];
	//[1,n] row | [n+1,2n] col
	forn(i,0,n) forn(j,0,n) if(s[i][j]=='o') adj[i+1].emp(j+1+n);
	ll x=0;
	forn(i,1,n+1){memset(vis,0,sizeof(vis)); if(!mat[i]) x+=dfs(i);}
	forn(i,1,n+1) if(!mat[i]) run(i);
	cout << x << '\n';
	forn(i,1,2*n+1){
		if(i<=n && !vs[i]) cout << 1 << ' ' << i << '\n';
		else if(i>n && vs[i]) cout << 2 << ' ' << (i-n) << '\n';
	}
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

