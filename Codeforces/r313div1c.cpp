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
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=2e5+1;
ll fac[mxN];
ll fsp(ll a,ll m){
	ll ans; ans=1;
	while(m){
		if(m&1) ans=(ans*a)%mdl1;
		a=(a*a)%mdl1,m>>=1;
	}
	return ans;
}
ll nCr(ll n,ll r){
	if(r>n) return 0;
	return (((fac[n]*fsp(fac[n-r],mdl1-2))%mdl1)*fsp(fac[r],mdl1-2))%mdl1;
}
void solve(istream &cin){
	ll r,c,n;
	cin>>r>>c>>n;
	ll dp[n+1];
	vc<ar<ll,2>> a(n+1);
	a[n][0]=r,a[n][1]=c;
	forn(i,0,n) cin>>a[i][0]>>a[i][1];
	sort(all(a));
	dp[0]=nCr(a[0][0]+a[0][1]-2,a[0][0]-1);
	forn(i,1,n+1){
			//a[i][0]+a[i][1]-2Ca[i][0]-1
		dp[i]=nCr(a[i][0]+a[i][1]-2,a[i][0]-1);
		forr(j,i-1,0) dp[i]=((dp[i]-dp[j]*nCr(a[i][0]+a[i][1]-a[j][0]-a[j][1],a[i][0]-a[j][0]))%mdl1+mdl1)%mdl1;
	}
	cout << dp[n] << '\n';
}

int main()
{
	fac[0]=1;
	forn(i,1,mxN) fac[i]=(fac[i-1]*i)%mdl1;
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
