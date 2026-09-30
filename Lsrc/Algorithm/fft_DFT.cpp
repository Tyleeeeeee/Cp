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
 
using cp=complex<double>;
const double pi=acos(-1);
ll n,m;
void fft(vc<cp> &arr,ll invert){
	ll mxN=arr.size();
	for(ll i=1,j=0;i<mxN;++i){
		ll bit; bit=mxN>>1;
		for(;j&bit;bit>>=1)j^=bit; j^=bit;
		if(i<j) swap(arr[i],arr[j]);
	}
	for(ll l=2;l<=mxN;l<<=1){
		double ang=(invert?-1:1)*2*pi/l;
		cp wlen(cos(ang),sin(ang));
		for(ll i=0;i<mxN;i+=l){
			cp w(1);
			for(ll j=0;j<l/2;++j){
				cp x,y; x=arr[i+j],y=arr[i+j+l/2]*w;
				arr[i+j]=x+y;
				arr[i+j+l/2]=x-y;
				w*=wlen;
			}
		}
	}
	if(invert) for(auto&v:arr) v/=mxN;
}
void solve(istream &cin){
	cin>>n>>m;
	vc<cp> a(n+1),b(m+1);
	forn(i,0,n+1){
		ll x; cin>>x;
		a[i]=cp(x);
	}
	forn(i,0,m+1){
		ll x; cin>>x;
		b[i]=cp(x);
	}
	ll N;
	for(N=1;N<n+m+2;N<<=1); a.resize(N),b.resize(N);
	fft(a,0);
	fft(b,0);
	forn(i,0,N) a[i]*=b[i];
	fft(a,1);
	vc<ll> res(n+m+1);
	forn(i,0,n+m+1) res[i]=round(a[i].real());
	forn(i,0,n+m+1) cout << res[i] << " \n"[i==n+m];
	// forn(i,0,n+m+1) cout << (ll)round(a[i].real()) << " \n"[i==n+m];
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
