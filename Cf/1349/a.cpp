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
 
//5 12 20 40
//5 3*2*2 2*2*5 2*2*2*5
constexpr ll mxN=2e5+1;
constexpr ll mxB=21;
ll n,dp[mxN][mxB]{},mp[mxN]{};
vc<ll> pr;
ll fsp(ll a,ll m){ll ans=1; for(;m;ans=(m&1?ans*a:ans),a=a*a,m>>=1); return ans;}
void solve(){
	cin >> n;
	forn(i,1,n+1){
		ll x; cin >> x;
		for(ll p=mp[x],cnt;x>1;p=mp[x]){
			cnt=0;
			while(x%p==0) x/=p,cnt++;
			dp[p][cnt]++;
		}
	}
	ll res=1;
	for(auto &p:pr) forr(j,19,1) {dp[p][j]+=dp[p][j+1]; if(dp[p][j]>=n-1){res*=fsp(p,j); break;}}
	cout << res << '\n';
}
int main()
{
	forn(i,2,mxN){
		if(!mp[i]) mp[i]=i,pr.emp(i);
		for(auto &p:pr){
			if(i*p>=mxN) break;
			mp[i*p]=p;
			if(i%p==0) break;
		}
	}
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
