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

vc<vc<ll>> dp(7,vc<ll>(2));
ll dfs(ll x){
    if(x<0) return 0;
    if(!x) return 1;
    ll sm; sm=0;
    forn(i,1,7) sm+=dfs(x-i);
    return sm;
}
vc<vc<ll>> mul(vc<vc<ll>> l,vc<vc<ll>> r){
    vc<vc<ll>> res(l.size(),vc<ll>(r[1].size()));
    forn(i,1,l.size()){
        forn(j,1,r[0].size()){
            ll x; x=0;
            forn(k,1,l.size()){
                x=(x+l[i][k]*r[k][j])%mdl1;
            }
            res[i][j]=x;
        }
    }
    return res;
}
ll mfsp(ll m){
    vc<vc<ll>> a(7,vc<ll>(7,0)),res(7,vc<ll>(7,0));
    forn(i,1,6) a[i][i+1]^=1;
    forn(i,1,7) a[6][i]^=1,res[i][i]^=1;
    while(m){
        if(m&1) res=mul(res,a);
        a=mul(a,a),m>>=1;
    }
    vc<vc<ll>> ans(7,vc<ll>(2));
    ans=mul(res,dp);
    return ans[6][1];
}
void solve(istream &cin){
    ll n;
    cin>>n;
    forn(i,1,7) dp[i][1]=dfs(i);
    cout << (n<=6?dp[n][1]:mfsp(n-6))%mdl1 << '\n';
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

