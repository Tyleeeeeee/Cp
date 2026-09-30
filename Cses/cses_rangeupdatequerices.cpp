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

ll n,q;
vc<ll> t(2000001,0),d(2000001,0);
void apply(ll p,ll val,ll k) {t[p]+=val*k,d[p]+=(p<n)?val:0;}
void build(ll p,ll k){while(p>1) p>>=1,k<<=1,t[p]=t[p<<1]+t[p<<1|1];}
void push(ll p){
    for(ll h=tdep(p);h;h--){
        if(d[p>>h]){
            apply((p>>h)<<1,d[p>>h],1<<(h-1));
            apply((p>>h)<<1|1,d[p>>h],1<<(h-1));
            d[p>>h]=0;
        }
    }
}
int main()
{
    fast_io;
    cin>>n>>q;
    forn(i,n,2*n) cin>>t[i]; forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];
    ll op,l,r,u;
    while(q--&&cin>>op){
        if(op==2) {
            cin >> l,push(l+n-1); 
            cout << t[l+n-1] << "\n";
        }
        else{
            cin>>l>>r>>u;
            ll l0,r0,k;
            l0=l+=n-1,r0=r+=n-1,k=1;
            for(;l<=r;l>>=1,r>>=1,k<<=1){
                if(l&1) apply(l++,u,k);
                if(!(r&1)) apply(r--,u,k);
            }
            build(l0,1),build(r0,1);
        }
    }
    return 0;
}


