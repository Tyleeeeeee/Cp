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
#define FAST 1
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
    #define TEST cerr << "test" << "\n"
#endif
#if FAST
    #define forn(a,b,c) for(ll a=b;a<c;++a)
    #define fast_io cin.tie(0),ios::sync_with_stdio(false)
#endif
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll mx5=100001; //1e5+1
constexpr ll mx9=1000000001; //1e9+1
constexpr ll mx6=1000001; //1e6+1
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define ps push
#define emp emplace_back
#define pb push_back
#define vc vector
#define ar array
#define uno unordered_map
#define pr pair
#define prq priority_queue
#define mls multiset
#define bg begin
#define ed end
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b)noexcept{if(!b) return a; while(a%=b) a^=b,b^=a,a^=b; return b;}
template<typename T> inline T lcm(T a,T b)noexcept{return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b)noexcept{return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c)noexcept{return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b)noexcept{return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c)noexcept{return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bct(T a)noexcept{return bitset<64>(a).count();}
template<typename T> inline T fsp(T a,T b){ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};

int main()
{
    fast_io;
    ll t,n,m,l,r;
    string s;
    cin>>t;
    while(t--&&cin>>n>>m>>s){
        vc<ll> ls(n+1,0);
        vc<pr<ll,ll>> pref(n+1,{0,0}),surf(n+2,{0,0});
        forn(i,1,n+1) ls[i]+=(s[i-1]=='-'?-1:1)+ls[i-1];
        forn(i,1,n+1){
            //range:ls[i-1] , ls[i-1]+s[i-1]=='-'?-1:1
            pref[i].fr=min(ls[i],pref[i-1].fr);
            pref[i].sc=max(ls[i],pref[i-1].sc);
            surf[n-i+1].fr=min(surf[n-i+1].fr,surf[n-i+2].fr+(s[n-i]=='-'?-1LL:1LL));
            surf[n-i+1].sc=max(surf[n-i+1].sc,surf[n-i+2].sc+(s[n-i]=='-'?-1LL:1LL));
        }
        forn(i,0,m){
            cin>>l>>r;
            ll lb,rb;
            lb=min(pref[l-1].fr,surf[r+1].fr+ls[l-1]);
            rb=max(pref[l-1].sc,surf[r+1].sc+ls[l-1]);
            cout << rb-lb+1 << "\n";
        }
    }
    return 0;
}


