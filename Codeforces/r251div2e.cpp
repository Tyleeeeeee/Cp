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

constexpr ll mxN=1e5+1;
vc<ll> fac[mxN],ft(mxN),mb(mxN,1),prime(mxN,0);
ll fsp(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?(ans*a)%mdl1:ans),a=(a*a)%mdl1,m>>=1); return ans;}
void solve(istream &cin){
	ll n,f; cin>>n>>f;
	ll l,r,m,res; l=1,r=1e5+1;
	while(r-l>1){
		m=(l+r)>>1;
		if(n/m>=f) l=m;
		else r=m;
	}
	res=0;
	for(auto&v:fac[n]){
		if(v>l) break;
		res=(res+mb[v]*(((((ft[n/v-1]*fsp(ft[n/v-f],mdl1-2))%mdl1)*fsp(ft[f-1],mdl1-2))%mdl1)%mdl1))%mdl1;
	}
	res=((res)%mdl1+mdl1)%mdl1;
	cout << res << '\n';
}
 
int main()
{
	mb[1]=ft[0]=1;
	forn(i,1,mxN){
		ft[i]=(i*ft[i-1])%mdl1;
		for(ll j=i;j<mxN;j+=i) fac[j].emp(i);
		if(!prime[i] && i>1){
			for(ll j=i;j<mxN;j+=i) prime[j]=1,mb[j]*=-1;
			for(ll j=i*i;j<mxN;j+=i*i) mb[j]=0;
		}
	}
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
