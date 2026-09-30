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
constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=1e6+1;
ll n,dp[mxN];
ar<ll,2> count(ll ind){
	ar<ll,2> a;
	forn(i,1,mxN) if(i*(i+1)/2>=ind){a[0]=i; break;}
	a[1]=ind-(a[0]-1)*a[0]/2;
	return a;
}
void solve(){
	cin >> n;
	cout << dp[n] << '\n';
}
int main()
{
	forn(i,1,mxN){
		auto [lv,rk]=count(i); //(1-based)
		ll s=(lv-2)*(lv-1)/2,x=(rk>1?s+rk-1:-1),y=(rk<lv?s+rk:-1),z=-1;
		if(~x && ~y){
			z=(lv-3)*(lv-2)/2+rk-1;
		}
		dp[i]=i*i+(~x?dp[x]:0)+(~y?dp[y]:0)-(~z?dp[z]:0);
	}
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
