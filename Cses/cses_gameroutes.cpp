 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Happy new year 2025
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
#include<queue>
#include<stack>
using namespace std;
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
// ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
constexpr ll mxN=1e5+1;
ll n,m;
vc<ll> adj[mxN],in(mxN,0),dp(mxN,0);
ll add(ll c,ll d){return (c%mdl1 + d%mdl1 + mdl1)%mdl1;}
void solve(istream &cin){
    cin>>n>>m;
    forn(i,1,m+1){
        ll u,v; cin>>u>>v;
        adj[u].emp(v);
        in[v]++;
    }
    dp[1]=1;
    ll f,r,q[mxN]; f=r=0;
    forn(i,1,n+1) if(!in[i]) q[r=(r+1)%mxN]=i;
    while(f!=r){
        ll u; u=q[f=(f+1)%mxN];
        for(auto&v:adj[u]){
            dp[v]=add(dp[v],dp[u]);
            in[v]--;
            if(!in[v]) q[r=(r+1)%mxN]=v;
        }
    }
    cout << dp[n] << '\n';
}
int main()
{
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

