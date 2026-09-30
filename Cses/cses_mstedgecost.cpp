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
ll n,m,pa[mxN],res,dp[mxN][20][2]{},d[mxN]{},ok[mxN]{},ans[mxN];
vc<pll> adj[mxN];
vc<ar<ll,4>> edg;
ll find(ll x){return pa[x]<0?x:pa[x]=find(pa[x]);}
void un(ll x,ll y){
	x=find(x),y=find(y); if(x==y) return;
	if(-pa[x]>-pa[y]) swap(x,y); pa[y]+=pa[x],pa[x]=y;
}
void kruskal(){
	memset(pa,-1,sizeof(pa));
	ll c=0;
	forn(i,0,m){
		auto &[w,u,v,ind]=edg[i];
		if(find(u)!=find(v)) un(u,v),adj[u].emp(pll{v,w}),adj[v].emp(pll{u,w}),c++,res+=w,ok[i]=1;
		if(c==n-1) break;
	}
}
void dfs(ll u=1,ll p=0){
	dp[u][0][0]=p,d[u]=d[p]+1;
	for(auto&[v,w]:adj[u]){
		if(v==p) continue;
		dp[v][0][1]=w;
		dfs(v,u);
	}
}
ll lca(ll u,ll v){
	ll mx;
	mx=0;
	if(d[u]<d[v]) swap(u,v);
	forr(i,19,0) if(d[u]-(1<<i)>=d[v]) mx=max(mx,dp[u][i][1]),u=dp[u][i][0];
	if(u==v) return mx;
	forr(i,19,0) if(dp[u][i][0]!=dp[v][i][0]) mx=max({mx,dp[u][i][1],dp[v][i][1]}),u=dp[u][i][0],v=dp[v][i][0];
	return max({mx,dp[u][0][1],dp[v][0][1]});
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,m+1){
		ll u,v,w; cin>>u>>v>>w;
		edg.emp(ar<ll,4>{w,u,v,i});
	}
	sort(all(edg));
	res=0;
	kruskal();
	dfs();
	forn(j,1,20) forn(i,1,n+1) dp[i][j][0]=dp[dp[i][j-1][0]][j-1][0],dp[i][j][1]=max(dp[i][j-1][1],dp[dp[i][j-1][0]][j-1][1]);
	forn(i,0,m){
		auto &[w,u,v,ind]=edg[i];
		if(ok[i]) ans[ind]=res;
		else ans[ind]=res+w-lca(u,v);
	}
	forn(i,1,m+1) cout << ans[i] << '\n';
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
