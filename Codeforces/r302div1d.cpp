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
 
constexpr ll mxN=2e5+1;
ll n,dp[mxN][2];
vc<ll> adj[mxN],pa(mxN);
ll fsp(ll p,ll m){
	ll ans; ans=1;
	for(;m;ans=(m&1?(ans*p)%mdl1:ans),p=(p*p)%mdl1,m>>=1);
	return ans;
}
void dfs(ll u=1,ll p=0){
	dp[u][0]=1;
	for(auto&v:adj[u]){
		dfs(v,u);
		dp[u][0]=(dp[u][0]*(dp[v][0]+1))%mdl1;
	}
}
void rdfs(ll u=1,ll p=0){
	if(u==1) dp[u][1]=0;
	vc<ll> pfx(adj[u].size()),sfx(adj[u].size());
	forn(i,0,adj[u].size()) pfx[i]=((i-1>=0?pfx[i-1]:1)*(dp[adj[u][i]][0]+1))%mdl1;
	forr(i,adj[u].size()-1,0) sfx[i]=((i<adj[u].size()-1?sfx[i+1]:1)*(dp[adj[u][i]][0]+1))%mdl1;
	forn(i,0,adj[u].size()){
		ll v; v=adj[u][i];
		dp[v][1]=((((i>0?pfx[i-1]:1)*(i+1<adj[u].size()?sfx[i+1]:1))%mdl1)*(dp[u][1]+1))%mdl1;
		// dp[v][1]=(((dp[u][0]*fsp(dp[v][0]+1,mdl1-2))%mdl1)*(dp[u][1]+1))%mdl1;
		rdfs(v,u);
	}
}
void solve(istream &cin){
	cin>>n;
	forn(i,2,n+1) cin>>pa[i],adj[pa[i]].emp(i);
	dfs();
	rdfs();
	// forn(i,1,n+1){err(i,dp[i][0],dp[i][1]);}
	forn(i,1,n+1) cout << (dp[i][0]*(dp[i][1]+1))%mdl1 << " \n"[i==n];
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
