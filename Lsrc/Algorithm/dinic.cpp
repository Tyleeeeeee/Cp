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
class fe{
	public:
		ll u,v,cp,fw;
		fe(){}
		fe(ll U,ll V,ll CP):u(U),v(V),cp(CP){fw=0;}
};
ll n,m,sz=0;
vc<fe> edg;
queue<ll> q;
vc<ll> adj[mxN],ptr,dep;
bool bfs(){
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(auto&id:adj[u]){
			if(edg[id].cp==edg[id].fw || dep[edg[id].v]!=-1) continue;
			dep[edg[id].v]=dep[u]+1,q.emplace(edg[id].v);
		}
	}
	return dep[n-1]!=-1;
}
ll dinic(ll u,ll push){
	if(!push) return 0;
	if(u==n-1) return push;
	for(ll &cid=ptr[u];cid<adj[u].size();++cid){
		ll id=adj[u][cid];
		ll v=edg[id].v;
		if(dep[v]!=dep[u]+1) continue;
		ll tr=dinic(v,min(push,edg[id].cp-edg[id].fw));
		if(!tr) continue;
		edg[id].fw+=tr,edg[id^1].fw-=tr;
		return tr;
	}
	return 0;
}
void solve(istream &cin){
	cin>>n>>m;
	ptr.resize(n),dep.resize(n);
	forn(i,1,m+1){
		ll u,v,c; cin>>u>>v>>c,u--,v--;
		edg.emp(fe{u,v,c}),edg.emp(fe{v,u,0});
		adj[u].emp(sz),adj[v].emp(sz+1),sz+=2;
	}
	ll res=0;
	for(;;){
		ll flow;
		fill(all(dep),-1);
		q.emplace(0),dep[0]=0;
		if(!bfs()) break;
		fill(all(ptr),0);
		for(;flow=dinic(0,inf);res+=flow);
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
