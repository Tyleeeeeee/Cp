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
 
constexpr ll mxN=1024+102;
ll n,k,ls[mxN],dp[mxN];
string a,b;
void solve(){
	cin >> n >> k >> a >> b;
	ll d=0;
	vc<ll> c;
	for(auto &ch:a) c.emp(ch-'a');
	memset(ls,-1,sizeof(ls));
	memset(dp,0,sizeof(dp));
	sort(all(c)),c.resize(unique(all(c))-c.bg()),d=c.size();
	for(auto &ch:a) ch=lwb(all(c),ch-'a')-c.bg();
	if(d<=k){cout << n*(n+1)/2 << '\n'; return;}
	forn(i,0,n){
		forn(j,0,(1<<d)){
			ll cur=(c[a[i]]==(b[i]-'a') || (1<<a[i]&j));
			if(cur) dp[j]+=ls[j]+1;
			else dp[j]+=i+1,ls[j]=i;
		}
	}
	// forn(i,0,(1<<d)){err(i,dp[i]);}
	ll res=inf;
	forn(i,0,(1<<d)) if(__builtin_popcount(i)<=k) MIN(res,dp[i]);
	cout << n*(n+1)/2-res << '\n';
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
