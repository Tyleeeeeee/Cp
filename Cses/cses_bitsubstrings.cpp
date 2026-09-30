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
 
using cp=complex<double>;
const double pi=acos(-1);
constexpr ll mxN=2e5+1;
ll n,m;
vc<cp> a(mxN<<2,{0,0}),b(mxN<<2,{0,0});
void fft(ll sz,vc<cp> &arr,ll inv){
	for(ll i=1,j=0;i<sz;++i){
		ll bit=sz>>1; for(;j&bit;bit>>=1) j^=bit; j^=bit;
		if(i<j) swap(arr[i],arr[j]);
	}
	for(ll l=2;l<=sz;l<<=1){
		double ang=(inv?-1:1)*2*pi/l;
		cp wlen(cos(ang),sin(ang));
		for(ll i=0;i<sz;i+=l){
			cp w(1,0);
			for(ll j=0;j<l/2;++j){
				cp x=arr[i+j],y=w*arr[i+j+l/2];
				arr[i+j]=x+y;
				arr[i+j+l/2]=x-y;
				w*=wlen;
			}
		}
	}
	if(inv) forn(i,0,sz) arr[i]/=sz;
}
void solve(istream &cin){
	string s; cin>>s; n=s.length();
	ll sum=0,cur,z; cur=z=0;
	a[0]=b[n-1]=cp(1,0);
	forn(i,0,n){
		sum+=(s[i]-'0');  a[sum]+=cp(1,0),b[n-sum-1]+=cp(1,0);
		if(s[i]=='0'){
			cur++;
			if(i==n-1) z+=cur*(cur+1)/2,cur=0;
		}
		else if(cur){
			z+=cur*(cur+1)/2,cur=0;
		}
	}
	ll x;
	for(x=1;x<n+n;x<<=1);
	fft(x,a,0),fft(x,b,0);
	forn(i,0,x) a[i]*=b[i];
	fft(x,a,1);
	cout << z << ' ';forn(i,n,2*n) cout << (ll)round((a[i].real())) << " \n"[i==2*n-1];
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
