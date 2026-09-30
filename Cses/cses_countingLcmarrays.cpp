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
#pragma GCC optimize ("03")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
vc<vc<ll>> a(2,vc<ll>(2,1));
vc<vc<ll>> mul(vc<vc<ll>> l,vc<vc<ll>> r){
	vc<vc<ll>> ans(l.size(),vc<ll>(r[0].size(),0));
	forn(i,0,l.size()){
		forn(j,0,r[0].size()){
			forn(k,0,l[0].size()){
				ans[i][j]=(ans[i][j]+l[i][k]*r[k][j])%mdl1;
			}
		}
	}
	return ans;
}
vc<vc<ll>> fsp(vc<vc<ll>> a,ll m){
	vc<vc<ll>> ans(2,vc<ll>(2,0)); ans[0][0]=ans[1][1]=1;
	while(m){
		if(m&1) ans=mul(ans,a);
		a=mul(a,a),m>>=1;
	}
	return ans;
}
vc<ll> f(ll k){
	vc<ll> ans;
	while(k>1){
		ll pre=k;
		for(ll i=2;i*i<=k;++i){
			if(k%i==0){
				ll x=0;
				while(k%i==0) k/=i,x++;
				ans.emp(x);
				break;
			}
		}
		if(k==pre){ans.emp(1); break;}
	}
	return ans;
}
void solve(istream &cin){
	ll n,k; cin>>n>>k;
	vc<ll> c=f(k);
	ll ans=1;
	for(auto&e:c){
		vc<vc<ll>> r(2,vc<ll>(1)); r[0][0]=e,r[1][0]=1,a[0][1]=e;
		vc<vc<ll>> b=fsp(a,n-1);
		r=mul(b,r);
		ans=(ans*(r[0][0]+r[1][0]))%mdl1;
	}
	cout << ans << '\n';
}
 
int main()
{
	a[0][0]=0;
    fast_io;
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
} 
