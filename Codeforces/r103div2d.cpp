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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const ll M = 991831889;
// const ll C = uniform_int_distribution<ll>(0.1 * M, 0.9 * M)(rng);

constexpr ll mxN=1e5+1;
ll n,m,s,l,d[mxN];
vc<ar<ll,3>> edg;
vc<ar<ll,2>> adj[mxN];
void djk(){
	mls<ar<ll,2>> hp;
	hp.emplace(ar<ll,2>{d[s]=0,s});
	while(!hp.empty()){
		auto [dis,u]=*hp.bg(); hp.erase(hp.bg());
		if(dis>d[u]) continue;
		for(auto&[v,w]:adj[u]){
			if(d[u]+w<d[v]) hp.emplace(ar<ll,2>{d[v]=d[u]+w,v});
		}
	}
}
void solve(istream &cin){
	cin >> n >> m >> s;
	memset(d,0x3f,sizeof(d));
	forn(i,0,m){
		ll u,v,w; cin >> u >> v >> w;
		edg.emp(ar<ll,3>{u,v,w});
		adj[u].emp(ar<ll,2>{v,w});
		adj[v].emp(ar<ll,2>{u,w});
	}
	cin >> l;
	djk();
	ll res=0;
	forn(i,1,n+1) res+=(d[i]==l);
	for(auto&[u,v,w]:edg){
		ll x=-1,y=-1;
		if(d[u]<l && d[u]+w>l && w-l+d[u]+d[v]>=l) x=l-d[u],res++;
		if(d[v]<l && d[v]+w>l && w-l+d[v]+d[u]>=l) y=l-d[v],res++;
		if(x!=-1 && y!=-1 && x+y==w) res--;
	}
	cout << res << '\n';
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
