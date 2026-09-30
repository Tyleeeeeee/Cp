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
ll n,m,mark[mxN]={0},vs[mxN]={0};
vc<ll> pa(mxN);
vc<pr<ll,pll>> edg,res;
vc<pll> adj[mxN],d(mxN,{inf,inf});
void bfs(ll u=1){
    ll f,r,q[mxN]; f=r=0;
    q[r=(r+1)%mxN]=1,vs[1]=1,d[1].fr=d[1].sc=0,pa[1]=-1;
    while(f^r){
        ll u; u=q[f=(f+1)%mxN];
        for(auto&[v,w]:adj[u]){
            if(d[u].fr+1==d[v].fr && d[u].sc+(w^1) < d[v].sc) d[v].sc=d[u].sc+(w^1),pa[v]=u;
            if(vs[v])
                continue;
            // err(u,v,d[u].fr+1,d[v].fr,d[u].sc+(w^1),d[v].sc);
            if(d[u].fr+1<d[v].fr) d[v].fr=d[u].fr+1,d[v].sc=d[u].sc+(w^1),pa[v]=u;
            q[r=(r+1)%mxN]=v,vs[v]=1;
        }
    }
    ll x; x=n;
    while(x^1) mark[x]=1,x=pa[x]; mark[1]=1;
}
void solve(istream &cin){
    cin>>n>>m;
    forn(i,1,m+1){
        ll u,v,z; cin>>u>>v>>z;
        adj[u].emp(pll{v,z}),adj[v].emp(pll{u,z});
        edg.emp(pr<ll,pll>{z,{u,v}});
    }
    bfs();
    for(auto&v:edg){
        if(v.sc.fr>v.sc.sc) swap(v.sc.fr,v.sc.sc);
        if(v.fr){
            if(mark[v.sc.fr] && mark[v.sc.sc]) continue;
            else res.emp(pr<ll,pll>{v.fr^1,{v.sc.fr,v.sc.sc}});
        }
        else{
            if(mark[v.sc.fr] && mark[v.sc.sc]) res.emp(pr<ll,pll>{v.fr^1,{v.sc.fr,v.sc.sc}});
            else continue;
        }
    }
    // forn(i,1,n+1){err(i,mark[i]);}
    // cerr << "\n--\n";
    cout << res.size() << '\n';
    for(auto&v:res) cout << v.sc.fr << ' ' << v.sc.sc << ' ' << v.fr << '\n';
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
