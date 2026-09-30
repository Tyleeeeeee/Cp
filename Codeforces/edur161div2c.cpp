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
#define prq priority_queue
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
template<typename T> inline T hsb(T a){ll cnt=1; while(a>>=1)cnt++; return cnt;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};

class SegT{
    private:
    ll n;
    vc<vc<ll>> t;
    // vc<ll> d;
 
    public:
    SegT(int size):n(size),t(2*size+5){}
    vc<ll> &operator[](int i){ return t[i]; }
    void built(){
        forr(i,n-1,1) merge(all(t[i<<1]),all(t[i<<1|1]),back_inserter(t[i]));
    }
    ll query(ll l,ll r){
        set<ll> ans;
        l+=n-1,r+=n-1;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) ans.insert(all(t[l])),l++;
            if(!(r&1)) ans.insert(all(t[r])),r--;
        }
        return ans.size();
    }
};

void solve(){
    ll n,m;
    cin>>n;
    vc<ll> a(n+2),pfx(n+1,0),sfx(n+2,0); forn(i,1,n+1)cin>>a[i]; cin>>m;
    a[0]=-inf,a[n+1]=inf;
    forn(i,2,n+1){
        pfx[i]=pfx[i-1]+(a[i-1]-a[i-2]>a[i]-a[i-1]?1:a[i]-a[i-1]);
        sfx[n-i+1]=sfx[n-i+2]+(a[n-i+2]-a[n-i+1]<a[n-i+3]-a[n-i+2]?1:a[n-i+2]-a[n-i+1]);
    }
    ll x,y;
    while(m--){
        cin>>x>>y;
        cout << (x<y?pfx[y]-pfx[x]:sfx[y]-sfx[x]) << '\n';
    }
}
int main()
{
    fast_io;
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

