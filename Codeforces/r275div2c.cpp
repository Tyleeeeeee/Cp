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
#include<iterator>
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
#define pr pair
#define pll pr<ll,ll>
#define heap priority_queue
#define mls multiset
#define bg begin
#define ed end
#define fr first
#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
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
template<typename T> inline T msb(T a){ll cnt=1; while(a>>=1)cnt++; return cnt;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};

class SegT{
    private:
    ll n;
    vc<ll> t;
    // vc<ll> d;
 
    public:
    SegT(int size):n(size),t(2*size+5){}
    ll &operator[](int i){ return t[i]; }
    void built(){
        forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];
    }
    ll query(ll l,ll r){
        ll ans;
        ans=0,l+=n-1,r+=n-1;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) ans+=t[l++];
            if(!(r&1)) ans+=t[r--];
        }
        return ans;
    }
};

void solve(){
    ll n,k;
    cin>>n>>k;
    if(k==1) {forn(i,1,n+1)cout << i << " \n"[i==n]; return;}
    vc<ll> ans;
    ll a,b;
    a=1,b=n;
    while(k-1) ans.emp(a),a+=(min(a,b)==a?1:-1),k--,swap(a,b);
    if(ans.size()<n){
        if(ans.back()==max(a,b)+1) forn(i,min(a,b),max(a,b)+1) ans.emp(i);
        else forr(i,max(a,b),min(a,b)) ans.emp(i);
    }
    forn(i,0,ans.size()) cout << ans[i] << " \n"[i==ans.size()-1];
} 
int main()
{
    fast_io;
    ll t;
    // cin>>t;
    t=1;
    while(t--)
        solve();
    return 0;
}



