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

constexpr ll mxN=5e5+1;
ll n,tin,t[mxN<<1]={0},lz[mxN<<1]={0},in[mxN],sub[mxN],pa[mxN];
vc<ll> adj[mxN];
void dfs(ll u=1,ll p=-1){
    in[u]=++tin,sub[u]=1;
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        dfs(v,u);
        pa[v]=u,sub[u]+=sub[v];
    }
}
ll msb(ll x){forr(i,30,0) if(x&(1<<i))return i; return -1;}
void apply(ll p,ll val){t[p]=val; if(p<n) lz[p]=val;}
void built(ll p){while(p>>=1) if(!lz[p]) t[p]=min(t[p<<1],t[p<<1|1]);}
void push(ll p){
    for(ll h=msb(n);h;h--){
        if(lz[p>>h]){
            apply((p>>h)<<1,lz[p>>h]);
            apply((p>>h)<<1|1,lz[p>>h]);
            lz[p>>h]=0;
        }
    }
}
void rst(ll l,ll r,ll val){
    ll lb,rb; lb=l+=n-1,rb=r+=n-1;
    push(lb),push(rb);
    for(;l<=r;l>>=1,r>>=1){
        if(l&1) apply(l++,val);
        if(!(r&1)) apply(r--,val);
    }
    built(lb),built(rb);
}
ll query(ll l,ll r){
    ll res; res=inf;
    push(l+=n-1),push(r+=n-1);
    for(;l<=r;l>>=1,r>>=1){
        if(l&1) res=min(res,t[l++]);
        if(!(r&1)) res=min(res,t[r--]);
    }
    return res;
}
void solve(istream &cin){
    cin>>n;
    forn(i,1,n){
        ll u,v; cin>>u>>v;
        adj[u].emp(v),adj[v].emp(u);
    }
    tin=0,dfs();
    ll q; cin>>q;
    while(q--){
        ll op,v; cin>>op>>v;
        if(op==1){
            if(v>1 && !query(in[v],in[v]+sub[v]-1)) rst(in[pa[v]],in[pa[v]],0);
            rst(in[v],in[v]+sub[v]-1,1);
        }
        else if(op==2) rst(in[v],in[v],0);
        else cout << query(in[v],in[v]+sub[v]-1) << '\n';
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

