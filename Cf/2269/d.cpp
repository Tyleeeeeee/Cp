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

//3 6 12={0,3,5,6,9,10,12,15} xb
//0000 0001
//0011 0010
//0101 0100
//0110 0111
//1001 1000
//1010 1011
//1100 1101
//1111 1110
constexpr ll mxN=2e5+1;
ll n,q,t[mxN<<1];
void pst(ll p,ll x){for(t[p+=n-1]=__builtin_popcountll(x)&1^1;p>>=1;t[p]=t[p<<1]+t[p<<1|1]);}
void solve(){
	cin >> n >> q;
	forn(i,1,n+1) cin >> t[i+n-1],t[i+n-1]=__builtin_popcountll(t[i+n-1])&1^1;
	forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];
	cout << t[1] << ' ';
	for(ll p,x;q--;){
		cin >> p >> x;
		pst(p,x);
		cout << t[1] << " \n"[!q];
	}
}
int main()
{
	// forn(k,1,6) forn(i,0,16) {err(k,i,i^(3*k));}
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
