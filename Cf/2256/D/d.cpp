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
 
//1011|1010|1101
//1101|1010|1011
//tot0-1 C c0-1  =f[tot0-1] * inv[c0-1] * inv[tot0-c0]
constexpr ll mxN=1e6+1;
ll f[mxN],n,a[4];
string s;
ll fsp(ll a,ll m){ll ans=1; for(;m;ans=(m&1?ans*a%mdl2:ans),a=a*a%mdl2,m>>=1); return ans;}
void solve(){
	cin >> n >> s;
	memset(a,0,sizeof(a));
	for(ll i=0,cnt=0;i<n;i++){
		a[s[i]-'0']++;
		if(i>0 && s[i]!=s[i-1]) a[s[i-1]-'0'+0b10]++,cnt=1;
		else cnt++;
		if(i==n-1) a[s[i]-'0'+0b10]++;
	}
	if(a[2]<=1 && a[3]<=1){cout << 1 << '\n'; return;}
	ll ans=f[a[0]-1]*fsp(f[a[2]-1],mdl2-2)%mdl2*fsp(f[a[0]-a[2]],mdl2-2)%mdl2*f[a[1]-1]%mdl2*fsp(f[a[3]-1],mdl2-2)%mdl2*fsp(f[a[1]-a[3]],mdl2-2)%mdl2;
	cout << ans << '\n';
}
int main()
{
	f[0]=1; forn(i,1,mxN) f[i]=i*f[i-1]%mdl2;
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
