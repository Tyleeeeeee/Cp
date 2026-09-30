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

constexpr ll mxN=2e5+5;
ll n,q,t[mxN]{},res[mxN]{};
vc<ar<ll,4>> Q[mxN];
void pad(ll p){for(;p<mxN;t[p]++,p+=p&-p);}
ll query(ll p){ll ans=0; for(;p;ans+=t[p],p-=p&-p); return ans;}
ll query(ll l,ll r){return query(r-1)-query(l-1);}
void solve(istream &cin){
	cin>>n>>q;
	vc<ll> a(n),b;
	for(auto&v:a) cin>>v;
	forn(i,0,q){
		ll l,r,A,B; cin>>l>>r>>A>>B;
		Q[r].emp(ar<ll,4>{A,B,1,i});
		Q[l-1].emp(ar<ll,4>{A,B,-1,i});
	}
	b=a,sort(all(b)),b.resize(unique(all(b))-b.bg());
	for(auto&v:a) v=(lwb(all(b),v)-b.bg())+1;
	forn(i,1,n+1){
		pad(a[i-1]);
		for(auto&[A,B,c,ind]:Q[i]){
			A=lwb(all(b),A)-b.bg()+1;
			B=upb(all(b),B)-b.bg()+1;
			res[ind]+=query(A,B)*c;
		}
	}
	forn(i,0,q) cout << res[i] << '\n';
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
