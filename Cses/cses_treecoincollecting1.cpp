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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=2e5+1;
constexpr ll mxB=21;
ll n,q,a[mxN],dp[mxN][2],pa[mxN][mxB][2],d[mxN]{};
vc<ll> adj[mxN];
void dfs(ll u=1,ll p=0){
	d[u]=d[p]+1;
	if(a[u]) dp[u][0]=dp[u][1]=0;
	for(auto&v:adj[u]) if(v!=p){dfs(v,u),dp[u][0]=min(dp[u][0],dp[v][0]+1);}
}
void dfs_r(ll u=1,ll p=0){
	ll x=adj[u].size();
	vc<ll> pfx(x,inf),sfx(x,inf);
	forn(i,0,x){
		if(i) pfx[i]=pfx[i-1],sfx[x-i-1]=sfx[x-i]; 
		if(adj[u][i]!=p) pfx[i]=min(pfx[i],dp[adj[u][i]][0]+1);
		if(adj[u][x-i-1]!=p) sfx[x-i-1]=min(sfx[x-i-1],dp[adj[u][x-i-1]][0]+1);
	}
	forn(i,0,x){
		ll v=adj[u][i];
		if(v!=p)
			pa[v][0][0]=u,pa[v][0][1]=min(dp[u][0],dp[u][1]),dp[v][1]=min({dp[v][1],dp[u][1]+1,i-1>=0?pfx[i-1]+1:inf,i+1<x?sfx[i+1]+1:inf}),dfs_r(v,u);
	}
}
ll lca(ll u,ll v){
	ll r1,r2; r1=0,r2=min({dp[u][0],dp[u][1],dp[v][0],dp[v][1]});
	if(d[u]<d[v]) swap(u,v);
	forr(i,mxB-1,0) if(d[u]-(1<<i)>=d[v]) r1+=(1<<i),r2=min(r2,pa[u][i][1]),u=pa[u][i][0];
	if(v==u) return r1+2*r2;
	forr(i,mxB-1,0)
		if(pa[u][i][0]!=pa[v][i][0]) 
			r1+=(1<<(i+1)),r2=min({r2,pa[u][i][1],pa[v][i][1]}),u=pa[u][i][0],v=pa[v][i][0];
	r1+=2,r2=min(r2,pa[u][0][1]);
	return r1+2*r2;
}
void solve(istream &cin){
	cin>>n>>q;
	forn(i,1,n+1) cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	forn(i,1,n){ll u,v; cin>>u>>v; adj[u].emp(v),adj[v].emp(u);}
	dfs();
	dfs_r();
	forn(j,1,mxB) 
		forn(i,1,n+1) 
			pa[i][j][0]=pa[pa[i][j-1][0]][j-1][0],pa[i][j][1]=min(pa[i][j-1][1],pa[pa[i][j-1][0]][j-1][1]);
	while(q--){
		ll u,v; cin>>u>>v;
		cout << lca(u,v) << '\n';
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
