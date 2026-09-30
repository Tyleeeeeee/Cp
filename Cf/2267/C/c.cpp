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

constexpr ll mxN=3e5+1;
ll n,x,a[mxN],mn[mxN]{};
void solve(){
	cin >> n >> x;
	forn(i,1,n+1) cin >> a[i];
	vc<ll> fac;
	for(ll u;x>1;){
		u=mn[x],fac.emp(u);
		while(x%u==0) x/=u;
	}
	ll res=0; 
	for(auto p:fac){
		ll s=0;
		forn(i,1,n+1) if(a[i]%p==0) s+=a[i];
		MAX(res,s);
	}
	cout << res << '\n';
}

int main()
{
	//err(2*3*5*7*11*13*17);
	vc<ll> pr;
	forn(i,2,mxN){
		if(!mn[i]) mn[i]=i,pr.emp(i);
		for(auto &p:pr){
			if(p*i>=mxN) break;
			mn[p*i]=p;
			if(i%p==0) break;
		}
	}
    fast_io;
    int testcase;
    cin>>testcase;
    while(testcase--)
        solve();
    return 0;
}
