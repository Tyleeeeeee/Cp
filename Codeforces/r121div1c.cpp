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
ll n,lz[mxN]={0},pa[mxN][20],d[mxN],res[mxN];
vc<ll> adj[mxN];
map<pll,ll> mp;
void dfs1(ll u=1,ll p=0){
    d[u]=d[p]+1,pa[u][0]=p;
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        dfs1(v,u);
    }
}
void add(ll x,ll y){
    ll lca;
    lz[x]++,lz[y]++;
    if(d[x]<d[y]) swap(x,y); 
    forr(i,19,0){
        if(d[x]-(1<<i)>=d[y]) x=pa[x][i];
    }
    if(x==y) lca=x;
    else{
        forr(i,19,0) if(pa[x][i]!=pa[y][i]) x=pa[x][i],y=pa[y][i];
        lca=pa[x][0];
    }
    lz[lca]-=2;
}
void dfs2(ll u=1,ll p=0){
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        dfs2(v,u);
        res[mp[{min(u,v),max(u,v)}]]=lz[v];
        lz[u]+=lz[v];
    }
}
void solve(istream &cin){
    cin>>n;
    forn(i,1,n){
        ll u,v; cin>>u>>v;
        if(u>v) swap(u,v);
        adj[u].emp(v),adj[v].emp(u);
        mp[{u,v}]=i;
    }
    d[0]=0;
    dfs1();
    forn(j,1,20) forn(i,1,n+1) pa[i][j]=pa[pa[i][j-1]][j-1];
    ll k; cin>>k;
    while(k--){
        ll u,v; cin>>u>>v;
        add(u,v);
    }
    dfs2();
    forn(i,1,n) cout << res[i] << " \n"[i==n-1];
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
