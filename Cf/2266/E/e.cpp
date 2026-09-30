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
 
constexpr ll mxN=2e5+102;
ll n,k,mp[mxN]{},g[mxN],ans[mxN];
void solve(){
	//g(1)=0
	//g(m)=1+p1+p1p2+...+p1p2..pk
	//    =1+p1(1+p2+..+p2...pk)
	//    =1+mp[m]*g(m/mp[m])
	ll res=0;
	cin >> n >> k;
	memset(ans,0x3f,8*(n+1));
	//x/d=m min(g(m)) d<=k
	forn(i,1,k+1) for(ll j=i;j<=n;j+=i) MIN(ans[j],g[j/i]);
	forn(i,1,n+1){
		ll x; cin >> x;
		if(x>k) res+=ans[x];
	}
	cout << res << '\n';
}
int main()
{
	vc<ll> p;
	forn(i,2,mxN){
		if(!mp[i]) mp[i]=i,p.emp(i);
		for(auto &pr:p){
			if(pr*i>=mxN) break;
			mp[pr*i]=pr;
			if(i%pr==0) break;
		}
	}
	g[1]=0;
	forn(i,2,mxN) g[i]=1+mp[i]*g[i/mp[i]];
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
