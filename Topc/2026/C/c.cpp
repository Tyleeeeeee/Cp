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
 
constexpr ll mxN=1e6+102;
ll k,l,n,m=0,st[mxN],e[mxN]{},dp[mxN]{},id;
ar<ll,2> t[mxN<<1];
void pst(ll p,ll val){for(t[p+=m-1][0]=val;p>>=1;t[p]=min(t[p<<1],t[p<<1|1]));}
ar<ll,2> query(ll l,ll r){
	ar<ll,2> ans={inf,inf};
	for(l+=m-1,r+=m-1;l<=r;l>>=1,r>>=1){
		if(l&1) MIN(ans,t[l++]);
		if(r&1^1) MIN(ans,t[r--]);
	}
	return ans;
}
void solve(){
	cin >> k >> l >> n;
	if(k==1){
		ll wt=0;
		forn(i,1,n+1){ll w;cin >> w,wt+=w;}
		cout << wt*(l-1) << '\n';
		return;
	}
	for(ll i=1,K=k;i<l;i++) m+=K,K*=k;
	forn(i,1,m+1) t[i+m-1]={0,i};
	forr(i,m-1,1) t[i]=min(t[i<<1],t[i<<1|1]);
	forn(i,1,n+1){
		ll w; cin >> w;
		id=0,st[++id]=0;
		//1 k^1 + ... k^{l-1} =(k^l-1)/(k-1);
		for(ll u=0,v;u*k+1<=m;v=query(u*k+1,u*k+k)[1],st[++id]=v,u=v);
		while(id){
			e[st[id]]+=w;
			if(st[id]*k+1<=m) dp[st[id]]=query(st[id]*k+1,st[id]*k+k)[0];
			if(st[id]) pst(st[id],dp[st[id]]+e[st[id]]);
			id--;
		}
	}
	cout << dp[0] << '\n';
}
int main()
{
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
