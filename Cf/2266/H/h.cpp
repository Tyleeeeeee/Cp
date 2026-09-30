 /*--------------\
/   author :Tey   \
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
ll n,m,b[mxN],t1[mxN<<1],t2[mxN<<1],L[mxN],R[mxN],posR[mxN],posL[mxN];
ll query(ll *t,ll l,ll r){
	ll ans=0;
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1) MAX(ans,t[l++]);
		if(r&1^1) MAX(ans,t[r--]);
	}
	return ans;
}
void upd(ll *t,ll p,ll v){p+=n-1; for(MAX(t[p],v);p>>=1;t[p]=max(t[p<<1],t[p<<1|1]));}
void solve(){
	cin >> n >> m;
	memset(t1,0,8*(2*n));
	memset(t2,0,8*(2*n));
	memset(posR,0,8*(n+1));
	memset(posL,0,8*(n+1));
	forn(i,1,m+1) cin >> b[i],posR[b[i]]=posL[b[i]]=i;
	forr(i,n-1,1) MIN(posR[i],posR[i+1]);
	forn(i,2,n+1) MIN(posL[i],posL[i-1]);
	ll res=-1;
	posR[n+1]=posL[0]=m+102;
	forr(i,m,1){
		//b[i] -> query(b[i]+1,n);
		if(posR[b[i]+1]>i) R[i]=1+query(t1,b[i]+1,n),upd(t1,b[i],R[i]);
		else R[i]=0;
		if(posL[b[i]-1]>i) L[i]=1+query(t2,1,b[i]-1),upd(t2,b[i],L[i]);
		else L[i]=0;
		if(posR[b[i]+1]>i && posL[b[i]-1]>i) MAX(res,L[i]+R[i]-1);
	}
	cout << (~res?n-res:res) << '\n';
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
