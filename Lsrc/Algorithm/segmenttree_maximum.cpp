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

ll n,q,op,l,r,val;
vc<ll> t(mx5,0),d(mx5,0);
void apply(ll l,ll vl) {t[l]+=vl,d[l]+=(l<n)?vl:0;}
void build(ll l) {while(l>1) l>>=1,t[l]=max(t[l<<1],t[l<<1|1])+d[l];}
void push(ll l){
    for(ll dep=tdep(n);dep;dep--){
        if(d[l>>dep]){
            apply((l>>dep)<<1,d[l>>dep]);
            apply((l>>dep)<<1|1,d[l>>dep]);
            d[l>>dep]=0;
        }
    }
}
void upd(ll l,ll r){
    ll l0,r0;
    l0=l,r0=r;
    for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
        if(l&1) apply(l++,val);
        if(!(r&1)) apply(r--,val);
    }
    build(l0),build(r0);
}
void query(ll l,ll r){
    ll res=0;
    push(l),push(r);
    for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
        if(l&1) res=max(res,t[l++]);
        if(!(r&1)) res=max(res,t[r--]);
    }
    cout << res << "\n";
}
int main()
{
    fast_io;
    cin>>n;
    forn(i,n,2*n) cin>>t[i];
    forr(i,n-1,1) t[i]=max(t[i<<1],t[i<<1|1]);
    forn(i,1,2*n) cerr << t[i] << " \n"[i==2*n-1];
    cin>>q;
    while(q-- && cin>>op){
        if(op==1){
            cin>>l>>r;
            query(l,r);
            forn(i,1,2*n) cerr << t[i] << " \n"[i==2*n-1];
        }
        else{
            cin>>l>>r>>val;
            upd(l,r);
            forn(i,1,2*n) cerr << t[i] << " \n"[i==2*n-1];
        }
    }
    return 0;
}


