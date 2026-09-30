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
ll n,m,doc,tin[mxN],tout[mxN],tim;
vc<ll> adj[mxN],pa(mxN,-1);
vc<pll> pac(mxN);
void dfs(ll u=1){
    tin[u]=++tim;
    for(auto&v:adj[u]){
        dfs(v);
    }
    tout[u]=tim;
}
ll find(ll x){return pa[x]<0?x:find(pa[x]);}
void un(ll x,ll y){
    x=find(x),y=find(y);
    if(x==y) return;
    pa[y]+=pa[x],pa[x]=y;
}
void solve(istream &cin){
    cin>>n>>m;
    tim=doc=0;
    vc<pll> query;
    while(m--){
        ll t; cin>>t;
        if(t==1){
            ll x,y; cin>>x>>y;
            un(x,y);
            adj[y].emp(x);
        }
        else if(t==2){
            ll x; cin>>x;
            pac[++doc]={x,find(x)};
        }
        else{
            ll x,i; cin>>x>>i;
            query.emp(pll{x,i});
        }
    }
    forn(i,1,n+1) if(pa[i]<0) dfs(i);
    for(auto&[x,i]:query){
        ll u,v; u=pac[i].sc,v=pac[i].fr;
        cout << (tin[x]>=tin[u] && tin[x]<=tout[u] && tin[x]<=tin[v] && tout[x]>=tout[v]?"YES":"NO") << '\n';
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
