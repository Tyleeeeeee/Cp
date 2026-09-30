#include<iostream>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<array>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
#else
    #define debug(x)
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll mx5=100001; //1e5+1
constexpr ll mx9=1000000001; //1e9+1
constexpr ll mx6=1000001; //1e6+1
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define pb(x) push_back(x)
#define vc vector
#define ar array
#define uno unordered_map
#define pr pair
#define bg begin
#define ed end
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b){return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c){return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b){return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c){return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bitcount(T a){return bitset<64>(a).count();}
template<typename T> inline T fastp(T a,T b){ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;}
constexpr ll mxN=2e5+1;

ll n;
ll dp[mxN][2];
vc<ll> adj[mxN];
void dfs(ll u=1,ll p=-1){
    for(auto &v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        dp[u][1]=max(dp[u][0]+dp[v][0]+1,dp[u][1]+max(dp[v][0],dp[v][1]));
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
}
int main()
{
    fast_io;
    cin>>n;
    for(int q=0,p,c;q<n-1;++q) cin>>p>>c,adj[p].pb(c),adj[c].pb(p);
    memset(dp,0,sizeof(dp));
    dfs();
    cout << max(dp[1][0],dp[1][1]) << "\n";
    return 0;
}
 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/


