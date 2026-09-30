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
ll n,m,c[mxN],res,in,scc;
vc<ll> adj[mxN],vs(mxN,0),dfn(mxN,0),low(mxN),sc(mxN),st;
vc<ll> radj[mxN],tc(mxN,0),ind(mxN,0),dp(mxN);
void tarjan(ll u){
    low[u]=dfn[u]=++in,vs[u]=1,st.emp(u);
    for(auto&v:adj[u]){
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(vs[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        scc++;
        while(st.back()^u) vs[st.back()]=0,sc[st.back()]=scc,tc[scc]+=c[st.back()],st.pop_back(); 
        vs[u]=0,sc[u]=scc,tc[scc]+=c[u],st.pop_back();
    }
}
void kahn(){
    forn(i,1,n+1){
        for(auto&v:adj[i]){
            if(sc[v]!=sc[i]) radj[sc[i]].emp(sc[v]),ind[sc[v]]++;
        }
    }
    ll f,r,q[mxN]; f=r=0;
    forn(i,1,scc+1){
        dp[i]=tc[i];
        if(!ind[i]) q[r=(r+1)%mxN]=i;
    }
    while(f!=r){
        ll u; u=q[f=(f+1)%mxN];
        res=max(res,dp[u]);
        for(auto&v:radj[u]){
            dp[v]=max(dp[v],dp[u]+tc[v]),ind[v]--;
            if(!ind[v]) q[r=(r+1)%mxN]=v;
        }
    }
}
void solve(istream &cin){
    ll sum; sum=0;
    cin>>n>>m;
    forn(i,1,n+1) cin>>c[i],sum+=c[i];
    forn(i,1,m+1){
        ll u,v; cin>>u>>v; adj[u].emp(v);
    }
    scc=in=0;
    forn(i,1,n+1) if(!dfn[i]) tarjan(i);
    res=0;
    kahn();
    cout << res << '\n';
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



