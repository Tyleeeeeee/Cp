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
constexpr ll mxN=1010;
//Edge u v c f
class Edge{
	public:
		ll u,v,c,f;
		Edge(){}
		Edge(ll U,ll V,ll C):u(U),v(V),c(C){f=0;}
};
ll n,m,vs[mxN]{},sz=0;
vc<ll> pa,ptr,adj[mxN],ans;
vc<Edge> edg;
vc<vc<ll>> res;
queue<ll> q;
bool bfs(){
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(auto&id:adj[u]){
			if(pa[edg[id].v]!=-1 || edg[id].c==edg[id].f) continue;
			pa[edg[id].v]=pa[u]+1,q.emplace(edg[id].v);
		}
	}
	return pa[n-1]!=-1;
}
ll dfs(ll u,ll flow){
	if(!flow) return 0;
	if(u==n-1) return flow;
	for(ll &cid=ptr[u];cid<adj[u].size();++cid){
		ll id=adj[u][cid];
		ll v=edg[id].v;
		if(pa[v]!=pa[u]+1) continue;
		ll tr=dfs(v,min(flow,edg[id].c-edg[id].f));
		if(!tr) continue;
		edg[id].f+=tr;
		edg[id^1].f-=tr;
		return tr;
	}
	return 0;
}
bool dfs_ans(ll u){
	if(vs[u]) return 0;
	ans.emp(u);
	if(u==n-1){
		cout << ans.size() << '\n';
		for(auto&x:ans) cout << x+1 << ' '; cout << '\n';
		return 1;
	}
	vs[u]=1;
	for(auto&id:adj[u]){
		if(id&1 || !edg[id].f) continue;
		if(dfs_ans(edg[id].v)){
			edg[id].f--,vs[u]=0;
			return 1;
		}
	}
	ans.pop_back();
	vs[u]=0;
	return 0;
}
void solve(istream &cin){
	cin>>n>>m;
	pa.resize(n),ptr.resize(n);
	forn(i,0,m){
		ll u,v; cin>>u>>v,u--,v--;
		edg.emp(Edge{u,v,1}),edg.emp(Edge{v,u,0});
		adj[u].emp(sz),adj[v].emp(sz+1),sz+=2;
	}
	ll flow=0;
	for(;;){
		fill(all(pa),-1);
		q.emplace(0),pa[0]=0;
		if(!bfs()) break;
		fill(all(ptr),0);
		for(ll nf;nf=dfs(0,inf);flow+=nf);
	}
	cout << flow << '\n';
	while(flow--){ans.clear(); dfs_ans(0);}
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
