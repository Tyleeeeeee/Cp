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
// ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=1e5+3;

ll n,q,store;
vc<ll> adj[mxN],sub(mxN),d(mxN),in(mxN);
void dfs(ll u=1,ll p=-1){
    sub[u]=1,in[u]=++store;
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        d[v]=d[u]+1;
        dfs(v,u);
        sub[u]+=sub[v];
    }
}
void pad(ll *t,ll p,ll x){ for(;p<=n;p+=p&-p) t[p]+=x;}
void rad(ll *t,ll l,ll r,ll x){
    pad(t,l,x);
    pad(t,r+1,-x);
}
ll query(ll *t,ll p){ll res; for(res=0;p;p-=p&-p) res+=t[p]; return res;}
void solve(istream &cin){
    ll t[mxN]={0},dp[mxN]={0};
    cin>>n>>q;
    forn(i,1,n){
        ll u,v; cin>>u>>v;
        adj[u].emp(v),adj[v].emp(u);
    }
    d[1]=store=0;
    dfs();
    while(q--){
        ll op; cin>>op;
        if(op){
            ll v; cin>>v;
            cout << query(t,in[v])+query(dp,d[v]) << '\n';
        }
        else{
            ll v,x,dist,ex; cin>>v>>x>>dist;
            if(v==1){
                rad(t,1,1,x);
                rad(dp,1,dist,x);
                continue;
            }
            ex=dist-d[v];
            // err(ex,max(in[v]-d[v]+1,in[v]-dist),min(in[v]+dist,in[v]+sub[v]-1));
            rad(t,max(in[v]-d[v]+1,in[v]-dist),min(in[v]+dist,in[v]+sub[v]-1),x);
            if(ex>=0) rad(t,1,1,x);
            if(ex>0){
                rad(dp,1,ex,x);
                rad(t,in[v]-d[v]+1,min(in[v]-d[v]+ex,in[v]+sub[v]-1),-x);
            }
        }
        // forn(i,1,n+1) cout << query(t,in[i]) << " \n"[i==n];
        // forn(i,1,n+1) cout << query(dp,d[i]) << " \n"[i==n];
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
