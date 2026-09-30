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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=2e5+1;
constexpr ll mxB=31;
ll n,q,dp[mxN][mxB]{},t[mxB][mxN<<1];
ll msb(ll x){forr(i,mxB-1,0) if(x&(1LL<<i)) return i; return -1;}
void built(){forn(i,0,mxB) forr(j,n-1,1) t[i][j]=min(t[i][j<<1],t[i][j<<1|1]);}
void query(ll l,ll r,vc<ll> &ok){
	fill(all(ok),inf);
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1){forn(i,0,mxB) ok[i]=min(ok[i],t[i][l]); l++;}
		if(r&1^1){forn(i,0,mxB) ok[i]=min(ok[i],t[i][r]); r--;}
	}
}
void solve(istream &cin){
	cin>>n>>q;
	memset(t,0x3f,sizeof(t));
	forn(i,1,n+1){ll x,y; cin>>x,y=msb(x); dp[i][y]+=x,t[y][i+n-1]=x;}
	forn(i,1,n+1){
		forn(j,0,mxB) dp[i][j]+=dp[i-1][j];
	}
	built();
	while(q--){
		ll l,r,s,res; cin>>l>>r; res=-1,s=0;
		vc<ll> ok(mxB);
		query(l,r,ok);
		for(ll i=0;i+1<mxB;++i){
			if(s<(1LL<<(i+1))-1 && ok[i]>s+1){
				res=s+1;
				break;
			}
			s+=dp[r][i]-dp[l-1][i];
		}
		cout << (res==-1?s+1:res) << '\n';
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
