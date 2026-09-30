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
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
void solve(){
	ll n,k; cin >> n >> k;
	vc<ll> fq,sfq;
	for(ll i=1,last=-1,cnt=0,cur;i<=n;++i){
		cin >> cur;
		if(i>1 && cur!=last) fq.emp(cnt),cnt=1;
		else cnt++;
		if(i==n) fq.emp(cnt);
		last=cur;
	}
	sort(all(fq)),sfq=fq;
	forr(i,sfq.size()-2,0) sfq[i]+=sfq[i+1];
	ll res=0,l=0;
	for(;l<fq.size();){
		ll m=fq.size()-l,d;
		d=abs(sfq[l]-k);
		if(d%m==0) res+=(sfq[l]<=k)||(sfq[l]>k && (fq[l]-1)*m>=d);
		for(ll p=l;l<fq.size() && fq[p]==fq[l];l++);
	}
	cout << res << '\n';
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
