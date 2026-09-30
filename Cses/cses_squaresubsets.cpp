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
 
constexpr ll mxN=5e3+1;
constexpr ll mxB=700;
ll n,prime[mxN]{},st[mxN],pos[mxN],sz=0,d=0;
vc<bitset<mxB>> basis(mxB);
void xorbasis(bitset<mxB> &bit){
	forr(i,mxB-1,0){
		if(bit[i]){
			if(basis[i].none()){basis[i]=bit,d++; break;}
			else bit^=basis[i];
		}
	}
}
ll fsp(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?(ans*a)%mdl1:ans),a=(a*a)%mdl1,m>>=1); return ans;}
void solve(istream &cin){
	cin>>n;
	forn(i,1,n+1){
		ll x; cin>>x;
		if(x==1) continue;
		bitset<mxB> bit;
		while(x>1){
			ll p=prime[x],c=0;
			while(x%p==0) x/=p,c++; bit[pos[p]]=(c&1);
		}
		xorbasis(bit);
	}
	cout << fsp(2,n-d) << '\n';
}
 
int main()
{
	forn(i,2,mxN){
		if(!prime[i]) prime[i]=i,pos[i]=sz,st[++sz]=i;
		forn(j,1,sz+1){
			if(i*st[j]>=mxN) break; prime[i*st[j]]=st[j]; if(i%st[j]==0) break;
		}
	}
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
} 
