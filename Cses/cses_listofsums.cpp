  /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<iostream>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
#include<complex>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<array>
#include<functional>
#include<iterator>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<queue>
#include<stack>
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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
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
#pragma GCC optimize ("03")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=5e3+1;
ll n,m;
bool ok(ll a0,vc<ll> &a,vc<ll> &b){
	ll ind=2;
	mls<ll> hp(all(b));
	//a[0]=a0,a[1]=b[0]-a[0],a[2]=b[1]-a[0],hp.emplace(a[1]+a[2]);
	a[0]=a0;
	forn(i,1,n){
		if(hp.empty()) return false;
		else a[i]=*hp.bg()-a[0];
		forn(j,0,i){
			auto it=hp.find(a[j]+a[i]);
			if(it!=hp.ed())hp.erase(it);
		}
	}
	return hp.empty();
}
void solve(istream &cin){
	cin>>n;
	m=n*(n-1)/2;
	vc<ll> a(n),b(m);
	for(auto&v:b) cin>>v; sort(all(b));
	//a[0]+a[1]=b[0] a[0]+a[2]=b[1] b[1]-b[0]=a[2]-a[1] b[i]=a[1]+a[2] i>1
	//b[i]+b[1]-b[0]=2*a[2]
	//b[i]-b[1]+b[0]=2*a[1]
	forn(i,2,n){
		ll x=b[1]-b[0];
		if((b[i]-x)&1|(b[i]+x)&1) continue;
		if(b[1]-(b[i]+x)/2==b[0]-(b[i]-x)/2){
			ll a0=b[1]-(b[i]+x)/2;
			if(a0>0){
				if(ok(a0,a,b)){ forn(i,0,n) cout << a[i] << " \n"[i==n-1]; return;}
			}
		}
	}
}
 
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
