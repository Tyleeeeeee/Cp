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
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=1e5+1;
ll n,m,pA[mxN][21];
vc<ll> adj[mxN],d(mxN),vs(mxN,0),sz(mxN),pa(mxN),dis(mxN,inf);
void dfs(ll u=1,ll p=0){
	pA[u][0]=p;
	for(auto&v:adj[u]){
		if(v==p)
			continue;
		d[v]=d[u]+1;
		dfs(v,u);
	}
}
ll sub(ll u=1,ll p=0){
	sz[u]=1;
	for(auto&v:adj[u]){
		if(v==p || vs[v]) continue;
		sz[u]+=sub(v,u);
	}
	return sz[u];
}
ll find(ll u=1,ll siz=0,ll p=0){
	for(auto&v:adj[u]) if(!vs[v] && v!=p && sz[v]*2>siz) return find(v,siz,u);
	return u;
}
void c_d(ll u=1,ll p=0){
	ll c; c=find(u,sub(u)),pa[c]=p,vs[c]=1;
	for(auto&v:adj[c]){
		if(vs[v])
			continue;
		c_d(v,c);
	}
}
ll lca(ll u,ll v){
	if(d[u]<d[v]) swap(u,v);
	forr(i,20,0) if(d[u]-(1<<i)>=d[v]) u=pA[u][i];
	if(u==v) return u;
	forr(i,20,0) if(pA[u][i]!=pA[v][i]) u=pA[u][i],v=pA[v][i];
	return pA[u][0];
}
ll dist(ll u,ll v){return d[u]+d[v]-2*d[lca(u,v)];}
void upd(ll u=1){
	ll v; v=u;
	while(v){
		dis[v]=min(dis[v],dist(v,u));
		v=pa[v];
	}
}

ll query(ll u=1){
	ll v,res; v=u,res=inf;
	while(v){
		res=min(res,dis[v]+dist(v,u));
		v=pa[v];
	}
	return res;
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,n){
		ll u,v; cin>>u>>v;
		adj[u].emp(v),adj[v].emp(u);
	}
	d[1]=0,dfs();
	forn(j,1,21) forn(i,1,n+1) pA[i][j]=pA[pA[i][j-1]][j-1];
	c_d();
	upd(1);
	while(m--){
		ll t,v; cin>>t>>v;
		if(t==1) upd(v);
		else cout << query(v) << '\n';
	}
}

int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
