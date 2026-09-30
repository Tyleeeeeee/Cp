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
ll n,a[mxN],dp[mxN];
void solve(){
	cin >> n;
	memset(a,0,8*(n+1));
	vc<ar<ll,2>> b;
	forn(i,1,2*n+1){
		ll x; cin >> x;
		if(a[x]) b.emp(ar<ll,2>{i,a[x]});
		else a[x]=i;
	}
	sort(all(b));
	dp[0]=(b[0][0]-b[0][1]+1)*(b[0][0]-b[0][1]+1)+(2*n-b[0][0]+b[0][1]-1);
	//[1,4] [2,3]
	forn(i,1,n){
		auto [r,l]=b[i];
		ll j=upb(b.bg(),b.bg()+i,ar<ll,2>{l,-1})-b.bg()-1;
		dp[i]=max(dp[i-1],(~j?dp[j]-(r-l+1):2*n-(r-l+1))+(r-l+1)*(r-l+1));
	}
	cout << dp[n-1] << '\n';
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
