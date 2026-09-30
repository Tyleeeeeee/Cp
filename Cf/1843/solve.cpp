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
 
constexpr ll mxN=1e5+1;
ll t[mxN<<1],n,m,q,op[mxN];
void pst(ll p,ll val){for(t[p+=n-1]=val;p>>=1;t[p]=t[p<<1]+t[p<<1|1]);}
ll query(ll l,ll r){
	ll ans=0;
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1) ans+=t[l++];
		if(r&1^1) ans+=t[r--];
	}
	return ans;
}
void solve(){
	cin >> n >> m;
	vc<ar<ll,2>> a(m);
	memset(t,0,8*(2*n+1));
	for(auto &[l,r]:a) cin >> l >> r;
	cin >> q;
	forn(i,1,q+1) cin >> op[i];
	ll l=0,r=q+1,mid;
	while(r-l>1){
		mid=l+r>>1;
		forn(i,1,mid+1) pst(op[i],1);
		ll cnt=0;
		forn(i,0,m){
			auto [L,R]=a[i];
			cnt+=query(L,R)>=(R-L+1)/2+1;
		}
		if(!cnt) l=mid;
		else r=mid;
		forn(i,1,mid+1) pst(op[i],0);
	}
	cout << (r<q+1?r:-1) << '\n';
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
