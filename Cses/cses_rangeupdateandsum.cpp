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
    #define err(x) cerr << #x << ':' << x << '\n' 
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
template<typename T> inline T tdep(T a){ll cnt=1; while(a>>=1)cnt++; return cnt;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};
template<typename Node>
class SegT{
    private:
    ll n;
    vc<Node> t;
    vc<ll> d,D;
 
    public:
    SegT(int size):n(size),t(2*size+5,0),d(size+1,0),D(size+1,0){}
    Node &operator[](int i){
        return t[i];
    }
    void init(){forr(i,n-1,1)t[i]=t[i<<1]+t[i<<1|1];}
    void apply(ll p,Node val,ll k) {t[p]+=val*k; if(p<n){if(D[p])D[p]+=val;else d[p]+=val;};}
    void build(ll p){
        ll k=1;
        for(;p>1;){
            p>>=1,k<<=1;
            if(!d[p] && !D[p]) t[p]=t[p<<1]+t[p<<1|1];
            else if(d[p]) t[p]=t[p<<1]+t[p<<1|1]+d[p]*k;
            else t[p]=D[p]*k;
        }
    }
    void push(ll P){
        for(ll h=tdep(n);h;h--){
            ll p=P>>h;
            if(D[p]||d[p]){
                if(D[p]){
                    t[p<<1]=t[p<<1|1]=D[p]*(1<<(h-1));
                    if((p<<1)<n){
                        D[p<<1]=D[p];
                        d[p<<1]=0;
                    }
                    if((p<<1|1)<n){
                        D[p<<1|1]=D[p];
                        d[p<<1|1]=0;
                    }
                    D[p]=0;
                }
                if(d[p]){
                    t[p<<1]+=d[p]*(1<<(h-1));
                    t[p<<1|1]+=d[p]*(1<<(h-1));
                    if((p<<1)<n){
                        if(D[p<<1]) D[p<<1]+=d[p];
                        else d[p<<1]+=d[p];
                    }
                    if((p<<1|1)<n){
                        if(D[p<<1|1]) D[p<<1|1]+=d[p];
                        else d[p<<1|1]+=d[p];
                    }
                    d[p]=0;
                }
            }
        }
    }
    // void upd(ll p,Node val) {for(t[p+=n-1]=val;p;p>>=1)t[p>>1]=t[p]+t[p^1];}//1-based;
    void upd(ll l,ll r,Node val){
        ll k,l0,r0;
        l0=(l+=n-1),r0=(r+=n-1),k=1;
        push(l),push(r);
        for(;l<=r;l>>=1,r>>=1,k<<=1){
            if(l&1) apply(l++,val,k);
            if(!(r&1)) apply(r--,val,k);
        }
        build(l0),build(r0);
    }
    ll query(ll l,ll r){
        ll res=0;
        l+=n-1,r+=n-1;
        push(l),push(r);
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) res+=t[l++];
            if(!(r&1)) res+=t[r--];
        }
        return res;
    }
    void sapply(ll p,ll val,ll k){t[p]=val*k; if(p<n){d[p]=0,D[p]=val;}}
    void supd(ll l,ll r,Node val){
        ll k,l0,r0;
        l0=(l+=n-1),r0=(r+=n-1),k=1;
        push(l),push(r);
        for(;l<=r;l>>=1,r>>=1,k<<=1){
            if(l&1) sapply(l++,val,k);
            if(!(r&1)) sapply(r--,val,k);
        }
        build(l0),build(r0);
    }
};
 
int main()
{
    fast_io;
    ll n,q;
    cin>>n>>q;
    SegT<ll> t(n); forn(i,0,n)cin>>t[i+n];
    t.init();
    ll op,l,r,val;
    while(q--&&cin>>op){
        if(op==3){
            cin>>l>>r;
            cout << t.query(l,r) << "\n";
        }
        else {
            cin>>l>>r>>val;
            if(op==1) t.upd(l,r,val);
            else t.supd(l,r,val);
        }
    }
    return 0;
}
 






