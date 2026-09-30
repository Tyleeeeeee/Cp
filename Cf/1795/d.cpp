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
 
constexpr ll mxN=3e5+1;
ll n,f[mxN];
ll fsp(ll a,ll m){ll ans=1;for(;m;ans=(m&1?ans*a%mdl2:ans),a=a*a%mdl2,m>>=1); return ans;}
void solve(){
	cin >> n;
	ll c=1;
	vc<ll> tmp;
	forn(i,1,n+1){
		ll x; cin >> x;
		tmp.emp(x);
		if(i%3==0){
			sort(all(tmp));
			if(tmp[0]==tmp[1] && tmp[1]==tmp[2]) c=c*3%mdl2;
			else if(tmp[0]==tmp[1])c=c*2%mdl2;
			tmp.clear();
		}
	}
	ll res=f[n/3]*fsp(f[n/6],mdl2-2)%mdl2*fsp(f[n/3-n/6],mdl2-2)%mdl2*c%mdl2;
	cout << res << '\n';
}
int main()
{
	f[0]=1;forn(i,1,mxN) f[i]=i*f[i-1]%mdl2;
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
