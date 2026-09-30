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
 
constexpr ll mxN=3e3+5;
ll n,k,res[mxN],t[mxN],l[mxN]{},r[mxN]{},u[mxN]{},d[mxN]{};
vc<ll> e[mxN];
string s[mxN];
void solve(ll si,ll sj){
	ll ci,cj; ci=si,cj=sj;
	memset(t,0,sizeof(t));
	while(ci>=0 && cj>=0){
		if(ci>0 && s[ci-1][cj]==s[ci][cj]) u[cj]++,d[cj]--;
		else{
			ll x; u[cj]=0;
			for(x=0;ci+x<n && s[ci+x][cj]==s[ci][cj];x++); d[cj]=x;
		}
		if(cj+1<n && s[ci][cj+1]==s[ci][cj]) r[ci]++,l[ci]--;
		else{
			ll x; r[ci]=0;
			for(x=0;cj-x>=0 && s[ci][cj-x]==s[ci][cj];x++); l[ci]=x;
		}
		ll L1,L2,sum; L1=min(l[ci],u[cj]+1),L2=min(d[cj],r[ci]+1),e[ci-L1+1].emp(ci+1),sum=0;
		for(ll i=ci+L2;i;i-=(i&-i)) sum+=t[i];
		res[s[ci][cj]-'A']+=L2-sum;
		for(auto&pos:e[ci]) for(ll i=pos;i<=n;i+=i&-i) t[i]++; e[ci].clear();

		ci--,cj--;
	}
}
void solve(istream &cin){
	cin>>n>>k;
	forn(i,0,n) cin>>s[i];
	forn(i,0,n-1) solve(i,n-1);
	forr(i,n-1,0) solve(n-1,i);
	forn(i,0,k) cout << res[i] << '\n';
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
