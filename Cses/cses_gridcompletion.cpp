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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=501;
ll n,a[mxN][2],cnt[mxN][2]{},fac[mxN];
string s[mxN];
ll add(ll x,ll y){return (x+y)%mdl1;}
ll mul(ll x,ll y){return (x*y)%mdl1;}
ll fsp(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?(ans*a)%mdl1:ans),a=(a*a)%mdl1,m>>=1); return ans;}
ll nCr(ll x,ll y){return mul(mul(fac[x],fsp(fac[x-y],mdl1-2)),fsp(fac[y],mdl1-2));}
void solve(istream &cin){
	cin>>n;
	forn(i,0,n) cin>>s[i];
	memset(a,-1,sizeof(a));
	forn(i,0,n) forn(j,0,n) if(s[i][j]!='.') a[i][s[i][j]-'A']=j,cnt[j][s[i][j]-'A']=1;
	ll c1,c2,c3,c4,cp,cq;
	c1=c2=c3=c4=cp=cq=0;
	forn(i,0,n){
		if(a[i][0]==-1) cp++;
		if(a[i][1]==-1) cq++;
		if(a[i][0]==-1 && a[i][1]==-1) c1++;
		else if(a[i][0]==-1 && !cnt[a[i][1]][0]) c2++;
		else if(a[i][1]==-1 && !cnt[a[i][0]][1]) c3++;
		if(!cnt[i][0] && !cnt[i][1]) c4++;
	}
	ll res; res=0;
	forn(i,0,min(c1,c4)+1){
		forn(j,0,c2+1){
			forn(k,0,c3+1){
				res=add(res,((i+j+k)&1?-1:1)*mul(mul(mul(mul(mul(mul(nCr(c1,i),nCr(c4,i)),fac[i]),nCr(c2,j)),nCr(c3,k)),fac[cp-i-j]),fac[cq-i-k]));
			}
		}
	}
	cout << (res%mdl1+mdl1)%mdl1 << '\n';
}
 
int main()
{
	fac[0]=1;
	forn(i,1,mxN) fac[i]=(fac[i-1]*i)%mdl1;
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
