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

constexpr ll mxN=3e5+1;
vc<ll> adj[mxN],d(mxN),D(mxN),pa(mxN),dep(mxN);
ll add(ll a,ll b){return (a%mdl2 + b%mdl2 + mdl2)%mdl2;}
void solve(istream &cin){
    ll n,res;
    cin>>n;
    forn(i,1,n+1) adj[i].clear(),D[i]=0;
    forn(i,2,n+1) cin>>pa[i],adj[i].emp(pa[i]),adj[pa[i]].emp(i);
    ll f,r,q[mxN],vs[n+1];
    f=r=res=0;
    memset(vs,0,sizeof(vs));
    q[r=(r+1)%mxN]=1,dep[1]=1,vs[1]=1,d[1]=D[1]=1;
    while(f!=r){
        ll u;
        u=q[f=(f+1)%mxN];
        if(u>1)
            d[u]=add(D[dep[pa[u]]],-d[pa[u]])+(pa[u]==1),D[dep[u]]=add(D[dep[u]],d[u]);
        res=add(res,d[u]);
        for(auto&v:adj[u]){
            if(vs[v])
                continue;
            dep[v]=dep[u]+1,pa[v]=u,vs[v]=1,q[r=(r+1)%mxN]=v;
        }
    }
    cout << res << '\n';
}
int main()
{
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

