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
template<typename T> inline T tdep(T a){ll cnt=0; while(a>>=1)cnt++; return cnt;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};
template<typename Node>
class SegT{
    private:
    ll n;
    vc<Node> t,d;

    public:
    SegT(int size):n(size),t(2*size+1),d(size,0){}
    Node &operator[](int i){
        return t[i];
    }
    void init(){forr(i,n-1,1)t[i]=t[i<<1]+t[i<<1|1];}
    void apply(ll p,Node val,ll k) {t[p]+=val*k; if(p<n)d[p]+=val;}
    void build(ll l,ll r){
        for(;l>1;){
            l>>=1,r>>=1;
            forr(i,r,l){
                if(!d[i]) t[i]=t[i<<1]+t[i<<1|1];
            }
        }
    }
    void push(ll l,ll r){
        for(ll h=tdep(n);h;h--){
            forn(i,(l>>h),(r>>h)+1){
                if(d[i]){
                    apply(i<<1,d[i],1<<(h-1));
                    apply(i<<1|1,d[i],1<<(h-1));
                    d[i]=0;
                }
            }
        }
    }
    void upd(ll p,Node val) {for(t[p+=n-1]=val;p;p>>=1)t[p>>1]=t[p]+t[p^1];}//1-based;
    void upd(ll l,ll r,Node val){
        ll k,l0,r0;
        l0=(l+=n-1),r0=(r+=n-1),k=1;
        push(l,l+1),push(r-1,r);
        for(;l<=r;l>>=1,r>>=1,k<<=1){
            if(l&1) apply(l++,val,k);
            if(!(r&1)) apply(r--,val,k);
        }
        // forn(i,1,2*n) cerr << t[i] << " \n"[i==2*n-1];
        build(l0,l0+1),build(r0-1,r0);
    }
    Node query(ll l,ll r){
        Node res={};
        push(l+=n-1,r+=n-1);
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) res+=t[l++];
            if(!(r&1)) res+=t[r--];
        }
        return res;
    }
};

int main()
{
    fast_io;
    ll n,q,x;
    cin>>n>>q;
    SegT<ll> t(n); forn(i,n,2*n)cin>>t[i];
    t.init();
    forn(i,1,2*n) cerr << t[i] << " \n"[i==2*n-1];
    ll op,l,r,val;
    while(q--&&cin>>op){
        if(op==1){
            cin>>l>>r;
            cerr << t.query(l,r) << "\n";
        }
        else {
            cin>>l>>r>>val;
            t.upd(l,r,val);
        }
        forn(i,1,2*n) cerr << t[i] << " \n"[i==2*n-1];
    }
    return 0;
}

