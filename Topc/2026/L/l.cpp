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
#define MAX(x,y) (x=max(x,y))
#define MIN(x,y) (x=min(x,y))
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=2e5+102;
ll n,t[mxN]{};
vc<ll> adj[mxN];
ll check(ll v,ll w){
	forn(i,0,adj[v].size()) if(adj[v][i]==w) return 1;
	return 0;
}
void del(ll u){
	t[u]=0;
	forn(i,0,adj[u].size())
		forn(j,i+1,adj[u].size()) if(check(adj[u][i],adj[u][j])) t[adj[u][i]]=t[adj[u][j]]=0;
}
void solve(){
	cin >> n;
	forn(i,0,(3*n/2)){
		ll u,v; cin >> u >> v;
		if(u!=v) adj[u].emp(v),adj[v].emp(u);
	}
	forn(i,1,n+1) sort(all(adj[i])),adj[i].resize(unique(all(adj[i]))-adj[i].bg());
	forn(i,1,n+1){
		//(u,adj[i][j],adj[i][k])
		forn(j,0,adj[i].size())
			forn(k,j+1,adj[i].size()) t[i]+=check(adj[i][j],adj[i][k]);//1=cc 0=not
	}
	vc<ll> res;
	forn(i,1,n+1){
		if(!t[i]) continue;
		if(t[i]==3){res.emp(i),res.emp(adj[i][0]),del(i),del(adj[i][0]); continue;}
		ar<ll,2> mx={0,-1};
		forn(j,0,adj[i].size()) if(t[adj[i][j]]>mx[0]) mx={t[adj[i][j]],adj[i][j]};
		if(mx[0]==2) res.emp(mx[1]),del(mx[1]);
		else res.emp(i);
		del(i);
	}
	cout << res.size() << '\n';
	if(res.size()) forn(i,0,res.size()) cout << res[i] << " \n"[i==res.size()-1];
}
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
