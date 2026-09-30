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

constexpr ll mxN=1e2+1;

ll n,m,k;
vc<vc<ll>> mul(vc<vc<ll>> l,vc<vc<ll>> r){
    vc<vc<ll>> ans(l.size(),vc<ll>(r.size(),0));
    forn(i,1,l.size()){
        forn(j,1,r[0].size()){
            ll sum; sum=0;
            forn(k,1,l[0].size()){
                ans[i][j]=(ans[i][j]+l[i][k]*r[k][j])%mdl1;
            }
        }
    }
    return ans;
}
void mul(vc<vc<ll>> adj,ll k){
    vc<vc<ll>> res(n+1,vc<ll>(n+1,0));
    forn(i,1,n+1) res[i][i]=1;
    while(k){
        if(k&1) res=mul(res,adj);
        adj=mul(adj,adj),k>>=1;
    }
    cout << res[1][n] << '\n';
}
void solve(istream &cin){
    cin>>n>>m>>k;
    vc<vc<ll>> adj(n+1,vc<ll>(n+1,0));
    forn(i,1,m+1){ll u,v; cin>>u>>v; adj[u][v]++;}
    if(k==1){cout << adj[1][n] << '\n'; return;}
    mul(adj,k);
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
