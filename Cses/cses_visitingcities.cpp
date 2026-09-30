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
//#define sc second
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
 
constexpr ll mxN=1e5+1;
ll n,m,d[mxN],id[mxN],sd[mxN],et[mxN]{},ret[mxN],pa[mxN],lb[mxN],f[mxN],tim=0;
vc<pll> adj[mxN];
vc<ll> g[mxN],rg[mxN],t[mxN],res;
void djk(){
	memset(d,0x3f,sizeof(d));
	mls<pll> hp;
	d[1]=0,hp.emplace(pll{d[1],1});
	while(!hp.empty()){
		auto [dis,u]=*hp.bg(); hp.erase(hp.bg());
		if(dis>d[u]) continue;
		for(auto&[v,w]:adj[u]) if(d[u]+w<d[v]) d[v]=d[u]+w,hp.emplace(pll{d[v],v});
	}
	forn(i,1,n+1) for(auto&[v,w]:adj[i]) if(d[i]+w==d[v]) g[i].emp(v);
}
void dfs(ll u=1){
	et[u]=++tim,ret[tim]=u;
	id[tim]=sd[tim]=pa[tim]=lb[tim]=tim;
	for(auto&v:g[u]){
		if(!et[v]) dfs(v),f[et[v]]=et[u];
		rg[et[v]].emp(et[u]);
	}
}
ll find(ll u,ll x=0){
	if(u==pa[u]) return x?-1:u;
	ll v=find(pa[u],x+1);
	if(v<0) return u;
	if(sd[lb[u]]>sd[lb[pa[u]]]) lb[u]=lb[pa[u]];
	pa[u]=v;
	return x?v:lb[u];
}
void built(){
	vc<ll> arr[n+1];
	forr(i,n,1){
		for(auto&v:rg[i]) sd[i]=min(sd[i],sd[find(v)]);
		if(i>1) arr[sd[i]].emp(i);
		for(auto&v:arr[i]){
			ll x=find(v);
			if(sd[v]==sd[x]) id[v]=sd[v];
			else id[v]=x;
		}
		if(i>1) pa[i]=f[i];
	}
	forn(i,2,n+1){if(sd[i]!=id[i]) id[i]=id[id[i]]; t[ret[i]].emp(ret[id[i]]),t[ret[id[i]]].emp(ret[i]);}
}
void dfs_ans(ll u=1,ll p=0){
	res.emp(u);
	if(u==n){sort(all(res)); cout << res.size() << '\n'; for(auto&v:res) cout << v << ' '; cout << '\n'; exit(0);}
	for(auto&v:t[u]) if(v!=p) dfs_ans(v,u);
	res.pop_back();
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,m+1) {ll u,v,w; cin>>u>>v>>w; adj[u].emp(pll{v,w});}
	djk();
	dfs();
	built();
	dfs_ans();
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
