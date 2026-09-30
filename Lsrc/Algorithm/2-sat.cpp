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
ll n,m,in,scc;
vc<ll> adj[2*mxN],radj[2*mxN],dfn(2*mxN,0),low(2*mxN),vs(2*mxN,0),g(2*mxN),opp(2*mxN),ind(2*mxN,0),res(2*mxN,0),st;
ll no(ll x){return x<=m?x+m:x-m;}
void tarjan(ll u){
    // err(u);
    low[u]=dfn[u]=++in,vs[u]=1,st.emp(u);
    for(auto&v:adj[u]){
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(vs[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        scc++;
        while(st.back()^u) g[st.back()]=scc,vs[st.back()]=0,st.pop_back(); g[u]=scc,vs[u]=0,st.pop_back();
    }
}
bool ok(){
    forn(i,1,m+1){
        if(g[i]==g[i+m]) return false;
        else opp[g[i]]=g[i+m],opp[g[i+m]]=g[i];
    }
    return true;
}
void kahn(){
    forn(i,1,2*m+1){
        for(auto &v:adj[i]){
            if(g[i]!=g[v]) radj[g[v]].emp(g[i]),ind[g[i]]++;
        }
    }
    ll f,r,q[2*mxN]; f=r=0;
    forn(i,1,scc+1) if(!ind[i]) q[r=(r+1)%(2*mxN)]=i;
    while(f!=r){
        ll u; u=q[f=(f+1)%(2*mxN)];
        if(!res[u]) res[u]=1,res[opp[u]]=2;
        for(auto&v:radj[u]){
            ind[v]--;
            if(!ind[v]) q[r=(r+1)%(2*mxN)]=v;
        }
    }
    forn(i,1,m+1) cout << (res[g[i]]==1?'+':'-') << " \n"[i==m];
}
void solve(istream &cin){
    cin>>n>>m;
    forn(i,1,n+1){
        ll x,y;
        char f,s;
        cin>>f>>x>>s>>y;
        x=(f=='+')?x:x+m,y=(s=='+')?y:y+m;
        adj[no(x)].emp(y),adj[no(y)].emp(x);
    }
    scc=in=0;
    forn(i,1,2*m+1) if(!dfn[i]) tarjan(i);
    if(!ok()){cout << "IMPOSSIBLE" << '\n'; return;}
    kahn();
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



