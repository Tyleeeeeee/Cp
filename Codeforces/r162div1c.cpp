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

constexpr ll mxN=1e5+1;
ll n,q;
void solve(istream &cin){
    cin>>n>>q;
    ll v[n+1],c[n+1];
    forn(i,1,n+1) cin>>v[i];
    forn(i,1,n+1) cin>>c[i];
    while(q--){
        ll a,b; cin>>a>>b;
        pll mx1,mx2; mx1=mx2={0,-1};
        vc<ll> dp(n+1,-inf);
        forn(i,1,n+1){
            dp[c[i]]=max({dp[c[i]],(dp[c[i]]!=-inf)?a*v[i]+dp[c[i]]:b*v[i],(mx2.sc==c[i]?mx1.fr:mx2.fr)+v[i]*b});
            if(dp[c[i]]>mx1.fr){
                if(mx1.sc==c[i] || mx2.sc==c[i]){
                    if(mx2.sc==c[i]) mx2={max(mx2.fr,dp[c[i]]),mx2.sc};
                    else mx1={max(mx1.fr,dp[c[i]]),mx1.sc};
                }
                else mx1={dp[c[i]],c[i]};
            }
            if(mx1.fr>mx2.fr) swap(mx1,mx2);
        }
        cout << max(0LL,mx2.fr) << '\n';
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

