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
#pragma GCC optimize ("03")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=501;
class Edge{
	public:
		ll u,v,c,w;
		Edge(){}
		Edge(ll U,ll V,ll C,ll W):u(U),v(V),c(C),w(W){}
};
ll n,m,k,pa[mxN],d[mxN],ok[mxN]{},sz=0;
vc<ll> adj[mxN],ans;
vc<Edge> edg;
bool spfa(){
	fill(d,d+n,inf);
	vc<ll> vs(n,0);
	queue<ll> q; q.emplace(0),d[0]=0;
	while(!q.empty()){
		ll u=q.front(); q.pop(),vs[u]=0;
		for(auto&id:adj[u]){
			if(edg[id].c>0 && d[edg[id].v]>d[u]+edg[id].w){
				d[edg[id].v]=d[u]+edg[id].w,pa[edg[id].v]=id;
				if(!vs[edg[id].v]){
					vs[edg[id].v]=1;
					q.emplace(edg[id].v);
				}
			}
		}
	}
	return d[n-1]!=inf;
}
bool dfs(ll u=0){
	if(ok[u]) return false;
	if(u==n-1){
		cout << ans.size()+1 << '\n';
		for(auto&v:ans) cout << v+1 << ' '; cout << n << '\n';
		return true;
	}
	ans.emp(u),ok[u]=1;
	for(auto&id:adj[u]){
		if((id&1) || edg[id].c) continue;
		if(dfs(edg[id].v)){
			edg[id].c--,ok[u]=0;
			return true;
		}
	}
	ans.pop_back(),ok[u]=0;
	return false;
}
void solve(istream &cin){
	cin>>n>>m>>k;
	forn(i,1,m+1){
		ll u,v; cin>>u>>v,u--,v--;
		edg.emp(Edge{u,v,1,1}),edg.emp(Edge{v,u,0,-1}),adj[u].emp(sz++),adj[v].emp(sz++);
	}
	ll flow=0,res=0;
	for(;spfa() && flow<k;){
		ll w=0,cf=k-flow;
		for(ll u=n-1;u;cf=min(cf,edg[pa[u]].c),u=edg[pa[u]].u);
		for(ll u=n-1;u;w+=edg[pa[u]].w,edg[pa[u]].c-=cf,edg[pa[u]^1].c+=cf,u=edg[pa[u]].u);
		res+=cf*w,flow+=cf;
	}
	cout << (flow==k?res:-1) << '\n';
	if(flow==k) while(flow--) ans.clear(),dfs(0);
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
