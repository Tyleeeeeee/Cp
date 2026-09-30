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
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=1e5+1;
ll n,m,pa[mxN][21],d[mxN]={0},dep[mxN];
vc<ll> adj[mxN];
void dfs(ll u=1,ll p=0){
    dep[u]=dep[p]+1,d[u]=1,pa[u][0]=p;
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        dfs(v,u);
        d[u]+=d[v];
    }
}
ll mv(ll x,ll dist){
    forr(i,20,0) if(dist&(1<<i)) x=pa[x][i];
    return x;
}
ll solve(ll u,ll v){
    if(u==v) return n;
    if(dep[u]<dep[v]) swap(u,v);
    ll U,V,dist; U=u,V=v,dist=0;
    forr(i,20,0){
        if(dep[u]-(1<<i)>=dep[v]) u=pa[u][i],dist+=1<<i;
    }
    if(u==v){
        if(dist&1) return 0;
        ll y;
        y=mv(U,(dist>>1)-1);
        U=mv(U,dist>>1);
        return d[U]-d[y];
    }
    forr(i,20,0){if(pa[u][i]!=pa[v][i]) u=pa[u][i],v=pa[v][i],dist+=1<<(i+1);}
    dist+=2;
    if(dist&1) return 0;
    if(mv(U,dist>>1)==pa[u][0]) return n-d[mv(U,dist>>1)]+d[pa[u][0]]-d[mv(U,(dist>>1)-1)]-d[mv(V,(dist>>1)-1)];
    ll x,y; x=mv(U,dist>>1),y=mv(V,dist>>1);
    return dep[x]>dep[pa[u][0]]?d[x]-d[mv(U,(dist>>1)-1)]:d[y]-d[mv(V,(dist>>1)-1)];
}
void solve(istream &cin){
    cin>>n;
    forn(i,1,n){
        ll u,v; cin>>u>>v;
        adj[u].emp(v),adj[v].emp(u);
    }
    dep[0]=0,dfs();
    forn(j,1,21) forn(i,1,n+1) pa[i][j]=pa[pa[i][j-1]][j-1];
    cin>>m;
    while(m--){
        ll u,v; cin>>u>>v;
        cout << solve(u,v) << '\n';
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

