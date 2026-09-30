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
 
constexpr ll mxN=2e5+1;
ll n,a[mxN],vs[mxN]{};
vc<pll> res[2];
void solve(istream &cin){
	ll ok=1;
	cin>>n;
	forn(i,1,n+1) cin>>a[i],ok&=!(a[i]-i);
	if(ok){cout << 0 << '\n'; return;}
	forn(i,1,n+1){
		if(!vs[i]){
			vc<ll> tmp; tmp.emp(i);
			for(ll u=a[i];u^i;tmp.emp(u),vs[u]=1,u=a[u]);
			ll m=tmp.size();
			if(m>1){
				if(m==2) res[0].emp(pll{tmp[0],tmp[1]});
				else{
					forn(j,1,m){
						if(j<m-j) res[0].emp(pll{tmp[j],tmp[m-j]});
						else break;
					}
					res[1].emp(pll{tmp[0],tmp[1]});
					forn(j,2,m){
						if(j<m-j+1) res[1].emp(pll{tmp[j],tmp[m-j+1]});
						else break;
					}
				}
			}
		}
	}
	cout << (res[1].empty()?1:2) << '\n';
	cout << res[0].size() << '\n';
	for(auto&[x,y]:res[0]) cout << x << ' ' << y << '\n';
	if(!res[1].empty()) cout << res[1].size() << '\n';
	for(auto&[x,y]:res[1]) cout << x << ' ' << y << '\n';
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
