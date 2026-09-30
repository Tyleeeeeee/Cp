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

constexpr ll mxN=2e5+1;
int n,m1,m2,pa[mxN];
vc<int> adj2[mxN],vs(mxN);
vc<pr<int,int>> adj1;
void dfs(ll u,ll p=-1){
    vs[u]=1;
    if(p==-1) pa[u]=u;
    for(auto&v:adj2[u]){
        if(vs[v])
            continue;
        pa[v]=pa[u];
        dfs(v,u);
    }
}
void solve(istream &cin){
    cin>>n>>m1>>m2;
    adj1.clear();
    forn(i,1,n+1) adj2[i].clear(),pa[i]=0,vs[i]=0;
    forn(i,1,m1+1){ll u,v; cin>>u>>v; if(u>v) swap(u,v); adj1.emp(pll{u,v});}
    ll c1,c2,res; c1=c2=res=0;
    forn(i,1,m2+1){
        ll u,v; cin>>u>>v;
        adj2[u].emp(v),adj2[v].emp(u);
    }
    forn(i,1,n+1) if(!pa[i]) dfs(i),c2++;
    forn(i,1,n+1) adj2[i].clear();
    for(auto&[u,v]:adj1){
        if(pa[u]!=pa[v]) res++;
        else adj2[u].emp(v),adj2[v].emp(u);
    }
    fill(1+vs.bg(),1+n+vs.bg(),0),fill(1+pa,1+n+pa,0);
    forn(i,1,n+1) if(!pa[i]) dfs(i),c1++;
    cout << res+c1-c2 << '\n';
}
int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

