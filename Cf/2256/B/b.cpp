 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
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
#define fast_io cin.tie(0),ios_base::sync_with_stdio(false)
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
#define MAX(x,y) (x=max(x,y))
#define MIN(x,y) (x=min(x,y))
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
//constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=2e5+1;
constexpr ll mod=mdl2;
ll n,dp[mxN][3][2];
string s;
void solve(){
	cin >> n >> s;
	dp[0][0][0]=dp[0][1][0]=dp[0][2][0]=(s[0]=='0'||s[0]=='?');
	dp[0][0][1]=dp[0][1][1]=dp[0][2][1]=(s[0]=='1'||s[0]=='?');
	forn(i,1,n){
		dp[i][0][0]=dp[i][1][0]=dp[i][2][0]=dp[i][0][1]=dp[i][1][1]=dp[i][2][1]=0;
		if(s[i]=='0' || s[i]=='?'){
			dp[i][0][0]=dp[i-1][1][0];
			dp[i][1][0]=dp[i-1][2][1];
		}
		if(s[i]=='1' || s[i]=='?'){
			dp[i][1][1]=dp[i-1][0][0];
			dp[i][2][1]=dp[i-1][1][1];
		}
	}
	cout << (dp[n-1][0][0]+dp[n-1][1][0]+dp[n-1][2][0]+dp[n-1][0][1]+dp[n-1][1][1]+dp[n-1][2][1])%mod << '\n';
}
int main()
{
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
