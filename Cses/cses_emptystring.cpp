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
 
constexpr ll mxN=505;
ll n,dp[mxN][mxN]{},C[mxN][mxN]{};
string s;
ll mul(ll x,ll y){return (x*y)%mdl1;}
void solve(istream &cin){
	cin>>s;
	n=s.length();
	if(n&1){cout << 0 << '\n'; return;}
	//C[n][i]=C[n-1][i]+C[n-1][i-1];
	C[0][0]=1;
	forn(i,1,mxN) {C[i][0]=1; forn(j,1,i+1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mdl1;}
	forn(i,0,n) dp[i+1][i]=1;
	for(ll len=2;len<=n;len+=2){
		for(ll l=0;l+len-1<n;l++){
			ll r; r=l+len-1;
			for(ll k=l+1;k<=r;k+=2){
				if(s[l]==s[k]) dp[l][r]=(dp[l][r]+mul(mul(dp[l+1][k-1],dp[k+1][r]),C[(r-l+1)/2][(k-l+1)/2]))%mdl1;
			}
		}
	}
	cout << dp[0][n-1] << '\n';
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
