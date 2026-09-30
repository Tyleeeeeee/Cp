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
 
constexpr ll mxN=1e6+1;
ll pos,pre[mxN],del[mxN],n;
string s;
void solve(){
	cin >> s >> pos,n=s.length();
	memset(del,0,8*n);
	ll l=-1,r=n-1,m;
	while(r-l>1){
		m=l+r>>1;
		//n-m n+(n-1)+...+(n-m) < pos
		ll x=n*(n+1)/2-(n-m-1)*(n-m)/2;
		if(x<pos) l=m;
		else r=m;
	}
	//n+(n-1)+...+(n-r+1)+(n-r)
	pos-=n*(n+1)/2-(n-r)*(n-r+1)/2;
	mls<ar<ll,2>> hp;
	forn(i,0,n){
		pre[i]=(i>0?i-1:-1);
		if(i+1<n && s[i]>s[i+1]) hp.emplace(ar<ll,2>{i,i+1});
	}
	while(r && hp.size()){
		auto [l,R]=*hp.bg(); hp.erase(hp.bg());
		del[l]=1,r--,pre[R]=pre[l];
		if(pre[l]!=-1 && s[pre[l]]>s[R]) hp.emplace(ar<ll,2>{pre[l],R});
	}
	forn(i,0,n){
		if(!del[i]) pos--;
		if(!pos){cout << s[i]; return;}
	}
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
