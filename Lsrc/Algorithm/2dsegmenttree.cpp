 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
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
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
    #define TEST cerr << "test" << "\n"
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define ps push
#define emp emplace_back
#define pb push_back
#define vc vector
#define ar array
#define uno unordered_map
#define pr pair
#define pll pr<ll,ll>
#define prq priority_queue
#define mls multiset
#define bg begin
#define ed end
#define fr first
#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll mx5=100001; //1e5+1
constexpr ll mx9=1000000001; //1e9+1
constexpr ll mx6=1000001; //1e6+1
template<typename T> inline T gcd(T a,T b)noexcept{if(!b) return a; while(a%=b) a^=b,b^=a,a^=b; return b;}
template<typename T> inline T lcm(T a,T b)noexcept{return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b)noexcept{return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c)noexcept{return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b)noexcept{return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c)noexcept{return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bct(T a)noexcept{return bitset<64>(a).count();}
template<typename T> inline T fsp(T a,T b){ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;}
template<typename T> inline T tdep(T a){ll cnt=0; while(a>>=1) cnt++; return cnt;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};

constexpr ll mxN=1e3;
vc<vc<ll>> t(mxN,vc<ll>(mxN));
int main()
{
    fast_io;
    ll n,m;
    cin>>n>>m;
    forn(i,n,2*n) forn(j,m,2*m) cin>>t[i][j];
    forn(i,n,2*n) forr(j,m-1,1) t[i][j]=t[i][j<<1]+t[i][j<<1|1];
    forr(i,n-1,1) forn(j,1,2*n) t[i][j]=t[i<<1][j]+t[i<<1|1][j];
    // forn(i,1,2*n){
    //     // cerr << "i:" << i << " ";
    //     forn(j,1,2*m) cerr << t[i][j] << " \n"[j==2*m-1];
    //     // cerr << "\n---\n";
    // }
    ll r1,c1,r2,c2,res;//0-based
    cin>>r1>>c1>>r2>>c2;
    res=0;
    for(r1+=n,r2+=n;r1<=r2;r1>>=1,r2>>=1){
        if(r1&1){
            ll l,r;
            for(l=c1+n,r=c2+n;l<=r;l>>=1,r>>=1){
                if(l&1) res+=t[r1][l++];
                if(!(r&1)) res+=t[r1][r--];
            }
            r1++;
        }
        if(!(r2&1)){
            ll l,r;
            for(l=c1+n,r=c2+n;l<=r;l>>=1,r>>=1){
                if(l&1) res+=t[r2][l++];
                if(!(r&1)) res+=t[r2][r--];
            }
            r2--;
        }
    }
    cout << res << "\n";
    return 0;
}

