#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define DEBUG 1
   #if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
       template<typename T,typename... Args>
       inline void debug (const T& val,const Args&... args){
           cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
       }
       #define terr cerr << "I am here" << '\n'
   #endif
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back
#define upb upper_bound
#define all(x) x.begin(),x.end()
using i128=__int128;

//10010103 200
//1001003 100
//1000100 100
//10001000 100
constexpr ll inf=0x3f3f3f3f3f3f3f3f;

constexpr ll mxN=2e5+1;
ll n,dp[mxN][2]{},res=0;
vc<ar<ll,2>> adj[mxN],g[mxN];
void dfs(ll u=1,ll p=0){
	dp[u][0]=1,g[u].emp(ar<ll,2>{inf,1});
	for(auto &[v,uw]:adj[u]){
		if(v!=p){
			//g[v][0]=weight g[v][1]=#
			ll c=0;
			dfs(v,u);
			for(auto &[vw,cnt]:g[v]) if(vw>uw) c+=cnt;
			if(c) g[u].emp(ar<ll,2>{uw,c});
			dp[u][0]+=c;
		}
	}
}
void rdfs(ll u=1,ll p=0){
	res+=dp[u][0]+dp[u][1]-1;
	sort(all(g[u]));
	forr(i,g[u].size()-2,0) g[u][i][1]+=g[u][i+1][1];
	for(auto &[v,uw]:adj[u]){
		if(v!=p){
			ll c=0;
			auto it=upb(all(g[u]),ar<ll,2>{uw,inf});
			if(it!=g[u].end()) c=(*it)[1];
			if(c) g[v].emp(ar<ll,2>{uw,c});
			dp[v][1]=c;
			rdfs(v,u);
		}
	}
}
void solve(){
	cin >> n;
	forn(i,1,n){ll u,v,w; cin >> u >> v >> w; adj[u].emp(ar<ll,2>{v,w}),adj[v].emp(ar<ll,2>{u,w});};
	dfs();
	rdfs();
	//forn(i,1,n+1){err(i,dp[i][0],dp[i][1]);}
	cout << res << '\n';
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	int testcase;
	testcase=1;
	//cin >> testcase;
	while(testcase--) solve();
	return 0;
}
