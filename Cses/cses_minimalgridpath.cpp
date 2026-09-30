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
 
constexpr ll mxN=3e3+1;
ll n,res[mxN<<1];
string s[mxN];
ar<ll,2> dir[2]={{0,1},{1,0}};
void solve(istream &cin){
	cin>>n;
	forn(i,0,n) cin>>s[i];
	vc<pll> dp;
	vc<ll> vs(n*n,0);
	res[0]=s[0][0]-'A',dp.emp(pll{0,0}),vs[0]=1;
	forn(i,0,2*n-2){
		ll mn;
		vc<pll> ndp;
		mn=inf;
		for(auto&[r,c]:dp){
			for(auto [dx,dy]:dir){
				if(r+dx<n && c+dy<n && s[r+dx][c+dy]-'A'<mn) mn=s[r+dx][c+dy]-'A';
			}
		}
		for(auto&[r,c]:dp){
			for(auto [dx,dy]:dir){
				if(r+dx<n && c+dy<n && !vs[(r+dx)*n+c+dy] && s[r+dx][c+dy]-'A'==mn)
					ndp.emp(pll{r+dx,c+dy}),vs[(r+dx)*n+c+dy]=1;
			}
		}
		dp=ndp;
		res[i+1]=mn;
	}
	forn(i,0,2*n-1) cout << (char)(res[i]+'A'); cout << '\n';
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
