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
 
constexpr ll mxN=150001;
ll n,m,d,dp[mxN],t[mxN<<1],a[mxN],b[mxN],ti[mxN];
void pst(ll p,ll val){for(t[p+=n-1]=val;p>1;p>>=1) t[p>>1]=max(t[p],t[p^1]);}
ll query(ll l,ll r){
    l=max(1LL,l),r=min(n,r);
    ll ans; ans=-inf;
    for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
        if(l&1) ans=max(ans,t[l++]);
        if(!(r&1)) ans=max(ans,t[r--]);
    }
    return ans;
}
void solve(istream &cin){
    cin>>n>>m>>d;
    forn(i,1,m+1) cin>>a[i]>>b[i]>>ti[i];
    memset(t,0,sizeof(t));
    forn(i,1,n+1) dp[i]=b[1]-abs(a[1]-i),pst(i,dp[i]);
    ll res; res=-inf;
    forn(i,2,m+1){
        forn(j,1,n+1){
            dp[j]=query(j-(ti[i]-ti[i-1])*d,j+(ti[i]-ti[i-1])*d)+b[i]-abs(a[i]-j);
            if(i==m) res=max(res,dp[j]);
        }
        forn(j,1,n+1) pst(j,dp[j]);
    }
    cout << res << '\n';
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
