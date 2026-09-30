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
 
ll fsp(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?(ans*a)%mdl1:ans),a=(a*a)%mdl1,m>>=1); return ans;}
void solve(istream &cin){
	ll n,m; cin>>n>>m;
	vc<vc<ll>> a(n,vc<ll>(m+1));
	forn(i,0,n) forn(j,0,m+1) cin>>a[i][j];
	for(ll l=0,i=0;i<m && l<n;++i){
		if(!a[l][i]) forn(j,l+1,n) if(a[j][i]){swap(a[j],a[l]); break;}
		if(!a[l][i]) continue;
		ll inv=fsp(a[l][i],mdl1-2);
		for(auto&v:a[l]) v=(v*inv)%mdl1;
		forn(j,l+1,n){ll co=a[j][i]; forn(k,i,m+1) a[j][k]=((a[j][k]-a[l][k]*co)%mdl1+mdl1)%mdl1;}
		l++;
	}
	vc<ll> res(m,0);
	forr(i,n-1,0){
		ll j=0; while(j<m+1 && !a[i][j]) j++;
		if(j==m+1) continue;
		if(j==m){cout << -1 << '\n'; return;}
		ll u=a[i][m];
		forn(k,j+1,m) u=((u-res[k]*a[i][k])%mdl1+mdl1)%mdl1;
		res[j]=u;
	}
	forn(i,0,m) cout << res[i] << " \n"[i==m-1];
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
