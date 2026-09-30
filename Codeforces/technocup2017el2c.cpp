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

constexpr ll mxN = 2e5+5;
ll n,k,s,t,mt;
vc<ll> g(mxN);
void solve(){
    ll lb,rb,mid;
    lb=2,rb=1e18;
    while(lb<=rb){
        mid=(lb+rb)/2;
        ll ok,cost;
        cost=0,ok=1;
        forn(i,0,k+1){
            //i->i+1 x=min(mid,(g[i+1]-g[i])) left=mid-x y=min(x,left) x=x-y y+2*x
            if(g[i+1]-g[i]>mid) ok=0;
            else{
                ll x=min(mid,g[i+1]-g[i]),y=min(x,mid-x);
                x=x-y;
                cost+=y+2*x;
            }
            if(cost>t) ok=0;
            if(!ok) break;
        }
        if(ok) mt=min(mt,mid),rb=mid-1;
        else lb=mid+1;
    }
}
int main()
{
    fast_io;
    cin>>n>>k>>s>>t;
    vc<pll> cv(n+1); forn(i,1,n+1)cin>>cv[i].fr>>cv[i].sc; forn(i,1,k+1) cin>>g[i];
    mt=inf,g[0]=0,g[k+1]=s;
    sort(allb(g)+k+2);
    solve();
    ll res;
    res=inf;
    forn(i,1,n+1) if(cv[i].sc>=mt) res=min(res,cv[i].fr);
    res=(res==inf?-1:res);
    cout << res << "\n";
    return 0;
}

