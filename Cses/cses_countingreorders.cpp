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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=5e3+1;
ll n,cnt[26]{},fac[mxN],nCr[mxN][mxN];
string s;
ll mul(ll x,ll y){return (x*y)%mdl1;}
ll fsp(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?mul(ans,a):ans),a=mul(a,a),m>>=1); return ans;}
void solve(istream &cin){
	cin>>s;
	n=s.length();
	for(auto&v:s) cnt[v-'a']++;
	vc<ll> dp(n+1,0);
	dp[0]=1;
	forn(i,0,26){
		if(!cnt[i]) continue;
		vc<ll> ndp(n+1,0);
		forn(x,1,cnt[i]+1){
			for(ll j=0;j+x<n+1;j++){
				ndp[j+x]=(ndp[j+x]+mul(mul(dp[j],nCr[j+x][x]),nCr[cnt[i]-1][x-1]))%mdl1;
			}
		}
		dp=ndp;
	}
	ll res=0;
	forr(i,n,1){
		if(i%2==n%2) res=(res+dp[i])%mdl1;
		else res=((res-dp[i])%mdl1+mdl1)%mdl1;
	}
	cout << res << '\n';
}
 
int main()
{
	nCr[0][0]=1;
	forn(i,1,mxN){
		nCr[i][0]=nCr[i][i]=1;
		forn(j,1,i) nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mdl1;
	}
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
