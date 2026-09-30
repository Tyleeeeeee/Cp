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
#pragma GCC optimize ("03")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
// char dir[4]={'L','D','R','U'};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

//mxN got problem also lca got problem
constexpr ll mxN=1e5+1;
constexpr ll mxB=20;
ll n,m,q,st[mxN],id=0,mark[mxN]{},dfn[mxN]{},low[mxN],tim=0,nid[mxN],pa[mxN<<1][mxB],d[mxN<<1];
vc<ll> adj[mxN];
vc<vc<ll>> cmp,t;
void tarjan(ll u=1,ll p=0){
	dfn[u]=low[u]=++tim,st[++id]=u;
	for(auto&v:adj[u]){
		if(v==p) continue;
		if(dfn[v]) low[u]=min(low[u],dfn[v]);
		else{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				mark[u]=(dfn[u]>1 || dfn[v]>2);
				cmp.emp(vc<ll>{u});
				while(cmp.back().back()!=v) cmp.back().emp(st[id--]);
			}
		}
	}
}
void dfs(ll u=1,ll p=0,ll lv=1){
	d[u]=lv,pa[u][0]=p;
	for(auto&v:t[u]){
		if(v!=p) dfs(v,u,lv+1);
	}
}
void built(){
	ll x=0;
	t.emp(vc<ll>{});
	forn(i,1,n+1) if(mark[i]) nid[i]=++x,t.emp(vc<ll>{});
	for(auto&a:cmp){
		ll y=++x;
		t.emp(vc<ll>{});
		for(auto&u:a){
			if(mark[u]) t[nid[u]].emp(y),t[y].emp(nid[u]);
			else nid[u]=y;
		}
	}
	err(t.size());
	dfs();
	forn(j,1,mxB) forn(i,1,t.size()) pa[i][j]=pa[pa[i][j-1]][j-1];
}
ll lca(ll a,ll b){
	if(d[a]<d[b]) swap(a,b);
	forr(i,mxB-1,0) if(d[a]-(1<<i)>=d[b]) a=pa[a][i];
	if(a==b) return a;
	forr(i,mxB-1,0) if(pa[a][i]!=pa[b][i]) a=pa[a][i],b=pa[b][i];
	return pa[a][0];
}
ll query(ll a,ll b,ll c){
	ll lca1=lca(a,b),lca2=lca(a,c),lca3=lca(b,c);
	return (lca1==c || (lca2==c && lca3==lca1) || (lca3==c && lca2==lca1));
}
void solve(){
	cin >> n >> m >> q;
	forn(i,0,m){
		ll u,v; cin >> u >> v;
		adj[u].emp(v),adj[v].emp(u);
	}
	tarjan();
	built();
	while(q--){
		ll a,b,c; cin >> a >> b >> c;
		cout << ((mark[c] && query(nid[a],nid[b],nid[c])) || a==c || b==c?"NO":"YES") << '\n';
	}
}
//g=(y2-y1)/(x2-x1)
//(y-y1)=(x-x1)*g
//y=x*g - x1*g + y1
int main()
{
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
