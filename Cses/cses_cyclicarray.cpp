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
 
constexpr ll mxN=4e5+1;
ll n,k,a[mxN],b[mxN],dp[mxN]{},nxt[mxN][22]{};
void solve(istream &cin){
	cin>>n>>k;
	forn(i,1,n+1) cin>>a[i],a[i+n]=a[i];
	ll c=0,res;
	queue<ll> q;
	forn(i,1,2*n+1){
		c+=a[i],q.emplace(i);
		while(c>k) nxt[q.front()][0]=i,c-=a[q.front()],q.pop();
	}
	forn(j,1,22) forn(i,1,2*n+1) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	forr(i,2*n,1){
		if(nxt[i][0]){
			dp[i]=dp[nxt[i][0]]+1;
			if(b[nxt[i][0]]-i+1<=n) b[i]=b[nxt[i][0]];
			else{
				ll x=i;
				forr(j,21,0){
					if(nxt[x][j] && nxt[x][j]-i+1<=n) x=nxt[x][j];
				}
				b[i]=x;
			}
		}
		else b[i]=i;
	}
	res=inf,c=0;
	forn(i,1,n+1){
		c+=a[i];
		res=min(res,dp[i]-dp[b[i]]+1);
		if(c>k) break;
	}
	cout << res << '\n';
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
