  /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<iostream>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
#include<complex>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<array>
#include<functional>
#include<iterator>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<queue>
#include<stack>
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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
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
//#pragma GCC optimize ("03")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
constexpr ll mxN=505;
ll n,m,adj[mxN][mxN]{},g[mxN][mxN]{};
vc<ll> pa;
ll bfs(){
	queue<pll> q; q.emplace(pll{0,inf});
	while(!q.empty()){
		auto [u,flow]=q.front(); q.pop();
		forn(i,0,n) 
			if(g[u][i] && adj[u][i] && pa[i]==-1){
				pa[i]=u;
				if(i==n-1) return min(flow,adj[u][i]);
				q.emplace(pll{i,min(flow,adj[u][i])});
			}
	}
	return 0;
}
void solve(istream &cin){
	cin>>n>>m;
	pa.resize(n);
	forn(i,1,m+1){ll u,v; cin>>u>>v,u--,v--; adj[u][v]=g[u][v]=1,adj[v][u]=g[v][u]=1;}
	ll f=0;
	fill(all(pa),-1),pa[0]=0;
	for(ll nf;nf=bfs();f+=nf){
		ll cur=n-1;
		while(cur) adj[pa[cur]][cur]-=nf,adj[cur][pa[cur]]+=nf,cur=pa[cur];
		fill(all(pa),-1),pa[0]=0;
	}
	vc<pll> res;
	forn(i,0,n) forn(j,0,n) if(g[i][j] && pa[i]!=-1 && pa[j]==-1) res.emp(pll{i,j});
	cout << res.size() << '\n';
	for(auto&[u,v]:res) cout << u+1 << ' ' << v+1 << '\n';
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
