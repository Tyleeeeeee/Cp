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
 
constexpr ll mxN=3e3+5;
ll dp[mxN][mxN];
void solve(istream &cin){
    ll n,k;
    cin>>n>>k;
    vc<ll> a(n+1),sfx(n+1);
    forn(i,1,n+1) cin>>a[i],sfx[i]=a[i];
    if(n==1){cout << 1 << '\n'; return;}
    //A B
    //->A B+1 a[A]>0 && sfx[B]<100
    //->B B+1 a[A]<100 && sfx[B]>0 
    //->B+1 B+2 a[A]>0 && sfx[B]>0
    memset(dp,-1,sizeof(dp));
    forr(i,n-1,1) sfx[i]=max(sfx[i],sfx[i+1]);
    ll f,r; f=r=0;
    pll q[mxN];
    q[r=(r+1)%mxN]={1,2},dp[1][2]=0;
    while(f^r){
        ll A,B; f=(f+1)%mxN;
        A=q[f].fr,B=q[f].sc;
        if(B>n) continue;
        if(a[A]>0 && sfx[B]<100 && dp[A][B+1]==-1) dp[A][B+1]=dp[A][B]+1,q[r=(r+1)%mxN]={A,B+1};
        if(a[A]<100 && sfx[B]>0 && dp[B][B+1]==-1) dp[B][B+1]=dp[A][B]+1,q[r=(r+1)%mxN]={B,B+1};
        if(a[A]>0 && sfx[B]>0 && dp[B+1][B+2]==-1) dp[B+1][B+2]=dp[A][B]+1,q[r=(r+1)%mxN]={B+1,B+2};
    }
    ll res; res=0;
    forn(i,1,n+2){
        forn(j,i+1,n+3){
            res+=(dp[i][j]<=k && dp[i][j]!=-1);
        }
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
