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

constexpr ll mxN = 2e5+2;
class Node{
    public:
        ll lb=inf;
        ll rb=0;
        bool inc=true;;
};
vc<Node> t(2*mxN);
ll tst,n,m,q;
void query(ll l,ll r){
    ll lb,rb,inc;
    lb=inf,rb=0,inc=true;
    for(;l<=r;l>>=1,r>>=1){
        if(l&1) inc=inc&&(rb<t[l].lb && t[l].rb<lb)&&t[l].inc,rb=max(rb,t[l].rb),l++;
        if(!(r&1)) inc=inc&&(t[r].rb<lb && t[r].lb>rb)&&t[r].inc,lb=min(t[r].lb,lb),r--;
    }
    cout << (inc?"YA":"TIDAK") << "\n";
}
void build(ll p){
    while(p>1) 
        p>>=1,t[p].lb=min(t[p<<1].lb,t[p<<1|1].lb),t[p].rb=max(t[p<<1].rb,t[p<<1|1].rb),t[p].inc=t[p<<1].inc&&t[p<<1|1].inc&&(t[p<<1].rb<t[p<<1|1].lb);
}
int main()
{
    fast_io;
    cin>>tst;
    while(tst--&&cin>>n>>m>>q){
        vc<ll> b(m+1);
        map<ll,ll> mp;
        vc<set<ll>> pos(n+1,set<ll>());
        ll x;
        forn(i,1,n+1) cin>>x,mp[x]=i,pos[i].insert(m+i);
        forn(i,1,m+1) cin>>b[i],pos[mp[b[i]]].insert(i);
        forn(i,n,2*n) t[i].lb=t[i].rb=*pos[i-n+1].bg(),t[i].inc=true;
        forr(i,n-1,1) {
            t[i].lb=min(t[i<<1].lb,t[i<<1|1].lb);
            t[i].rb=max(t[i<<1].rb,t[i<<1|1].rb);
            t[i].inc=(t[i<<1].inc && t[i<<1|1].inc && t[i<<1].rb<t[i<<1|1].lb);
        }
        query(n,2*n-1);
        ll s,o;
        while(q--&&cin>>s>>o){
            pos[mp[b[s]]].erase(s);
            t[mp[b[s]]+n-1].lb=t[mp[b[s]]+n-1].rb=*pos[mp[b[s]]].bg();
            build(mp[b[s]]+n-1);
            b[s]=o;
            pos[mp[b[s]]].insert(s);
            t[mp[b[s]]+n-1].lb=t[mp[b[s]]+n-1].rb=*pos[mp[b[s]]].bg();
            build(mp[b[s]]+n-1);
            query(n,2*n-1);
        }
    }
    return 0;
}





