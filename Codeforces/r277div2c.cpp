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
#include<cstdlib>
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
#define rbg rbegin
#define bg begin
#define ed end
#define fr first
#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
namespace TLX{
    template<typename T> inline T gcd(T a,T b)noexcept{
        if(!b) return a; while(a%=b) a^=b,b^=a,a^=b; return b;
    }
    template<typename T> inline T lcm(T a,T b)noexcept{
        return a*b/gcd(a,b);
    }
    template<typename T> inline T add(const T&a,const T&b){
        return ((a%mdl1)+(b%mdl1))%mdl1;
    }
    template<typename T,typename ...Args> inline T add(const T&a,const Args&...args){
        return ((a%mdl1)+add(args...))%mdl1;
    }
    template<typename T,typename ...Args> inline T mul(const T&a,const T&b){
        return ((a%mdl1) * (b%mdl1))%mdl1;
    }
    template<typename T,typename ...Args> inline T mul(const T &a,const Args&... args){
        return ((a%mdl1) * mul(args...))%mdl1;
    }
    template<typename T> inline T bct(T a)noexcept{
        return bitset<64>(a).count();
    }
    template<typename T> inline T fsp(T a,T b){
        ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;
    }
    template<typename T> inline T ffsp(T a,T b){
        ll ans=1; while(b){if(b&1)ans*=a; a*=a,b>>=1;}return ans;
    }
    template<typename T> inline T msb(T a){
        ll cnt=1; while(a>>=1)cnt++; return cnt;
    }
    template<typename T> void fib(T n,T &x,T &y){
        if(n==0){
            x=0,y=1;
            return;
        }
        if(n&1){
            fib(n-1,y,x);//y=Fn-1 x=Fn
            y=add(y,x);//y=Fn+1 x=Fn
        }
        else{
            ll a,b;
            fib(n>>1,a,b);//a=Fn b=Fn+1
            y=add(mul(a,a),mul(b,b));//Fn*Fn + Fn+1*Fn+1 = F2*n+1
            x=add(mul(b,a),mul(a,add(b-a,mdl1)));//F2*n
        }
    }
    class gtr{public:bool operator()(pll a,pll b)const{if(a.fr!=b.fr)return a.fr>b.fr; else return a.sc<b.sc;}};
    class lss{public:bool operator()(pll a,pll b)const{if(a.fr!=b.fr)return a.fr<b.fr; else return a.sc<b.sc;}};
}
class Node{
    public:
        ll val;
    
    Node(){}
    Node(ll v):val(v){}
    friend Node operator+(const Node&a,const Node&b){
        return min(a.val,b.val);
    }
};

class Segt{
    private:
    ll n;
    vc<Node> t;
    vc<ll> lz;
 
    public:
    Segt(int size):n(size),t(2*size+5),lz(size+1,0){}
    Node &operator[](int i){ return t[i]; }
    void combine(Node &p,Node &l,Node &r){p=l+r;}
    void built(){ forr(i,n-1,1) combine(t[i],t[i<<1],t[i<<1|1]);}
    void apply(ll p,ll val,ll k){ t[p].val^=k*val; if(p<n) lz[p]+=val; }
    void push(ll p){
        for(ll h=TLX::msb(n);h;h--){
            if(lz[p>>h]){
                apply((p>>h)<<1,lz[p>>h],1);
                apply((p>>h)<<1|1,lz[p>>h],1);
                lz[p>>h]=0;
            }
        }
    }
    // void built(ll p){while(p>1){p>>=1,combine(t[p],t[p<<1],t[p<<1|1]);}}
    void built(ll p){while(p>1) {p>>=1;if(!lz[p])combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void pad(ll p,ll val) {for(t[p+=n-1].val+=val;p;p>>=1)combine(t[p>>1],t[p],t[p^1]);}
    // void pst(ll p,ll val){for(t[p+=n-1]={val,val,val,val};p;p>>=1)combine(t[p>>1],(p&1?t[p^1]:t[p]),p&1?t[p]:t[p^1]);}
    void rad(ll l,ll r,ll val){
        ll l0,r0,k;
        k=1,l0=l+=n-1,r0=r+=n-1;
        push(l0),push(r0);
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) apply(l++,val,k);
            if(!(r&1)) apply(r--,val,k);
        }
        built(l0),built(r0);
    }
    Node query(ll l,ll r){
        // push(l+=n-1),push(r+=n-1);
        Node ans(inf);
        l+=n-1,r+=n-1;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) ans=ans+t[l++];
            if(!(r&1)) ans=t[r--]+ans;
        }
        return ans;
    }
    
};
class DSU{
    private:
        ll n;
        vc<ll> pa;

    public:
        DSU(){}
        DSU(ll N):n(N),pa(N+1,-1){}
        ll find(ll p){return pa[p]<0?p:pa[p]=find(pa[p]);}
        ll query(ll p){return -pa[find(p)];}
        void un(ll p,ll q){
            ll x,y;
            x=find(p),y=find(q);
            if(x==y) return;
            if(-pa[y]>-pa[x]) swap(x,y);
            pa[x]+=pa[y],pa[y]=x;
        }
};
using namespace TLX;

void solve(){
    ll n,p;
    string s;
    cin>>n>>p>>s; p--;
    ll s1,s2,l,r,res;
    pll x({-1,-1}),y({-1,-1});
    res=0,s1=s2=0,l=0,r=n-1;
    while(l<=r){
        if(s[l]!=s[r]) res+=min(abs(s[r]-s[l]),abs(26-abs(s[r]-s[l])));
        if(l<(n+1)/2 && s[l]!=s[r] && x.fr==-1) x.fr=l;
        if(l<(n+1)/2 && s[l]!=s[r] ) x.sc=l;
        if(r>(n-1)/2 && s[l]!=s[r] && y.fr==-1) y.fr=r;
        if(r>(n-1)/2 && s[l]!=s[r] ) y.sc=r;
        l++,r--;
    }
    if(!res){cout << res << '\n'; return;}
    if((n&1) && p==n/2) res+=abs(p-x.fr);
    else if(p<(n+1)/2) res+=(x.sc-x.fr)+min(abs(p-x.fr),abs(p-x.sc));
    else res+=(y.fr-y.sc)+min(abs(p-y.fr),abs(p-y.sc));
    cout << res << '\n';
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


