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
template<typename T> inline T gcd(T a,T b)noexcept{if(!b) return a; while(a%=b) a^=b,b^=a,a^=b; return b;}
template<typename T> inline T lcm(T a,T b)noexcept{return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b)noexcept{return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c)noexcept{return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b)noexcept{return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c)noexcept{return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bct(T a)noexcept{return bitset<64>(a).count();}
template<typename T> inline T fsp(T a,T b){ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;}
template<typename T> inline T ffsp(T a,T b){ll ans=1; while(b){if(b&1)ans*=a; a*=a,b>>=1;}return ans;}
template<typename T> inline T msb(T a){ll cnt=1; while(a>>=1)cnt++; return cnt;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};
class Node{
    public:
    ll val;
    // ll pfx;
    Node(){}
    Node(ll v):val(v){}
    friend Node operator+(const Node&a,const Node&b){
        return max(a.val,b.val);
    }
};
class Fent{
    public:
        ll n;
        vc<ll> a;
        vc<ll> t;

    public:
        Fent(int size):n(size),a(size+1),t(size+1,0){};
        ll &operator[](int i){ return a[i]; }
        void built(){
            forn(i,1,n+1){
                t[i]+=a[i];
                if(i+(i&-i)<=n) t[i+(i&-i)]+=t[i];
            }
        }
        void pad(ll p,ll val){
            for(;p<=n;p+=p&-p){
                t[p]+=val;
            }
        }
        ll query(ll p){
            ll ans=0;
            for(;p;p-=p&-p){
                ans+=t[p];
            }
            return ans;
        }
};

class Segt{
    private:
    ll n;
    vc<Node> t;
    // vc<ll> lz;
 
    public:
    Segt(int size):n(size),t(2*size+5){}
    Node &operator[](int i){ return t[i]; }
    void combine(Node &p,Node &l,Node &r){p=l+r;}
    void built(){ forr(i,n-1,1) combine(t[i],t[i<<1],t[i<<1|1]);}
    // void push(ll p){
    //     for(ll h=msb(n);h;h--){
    //         if(lz[p>>h]){
    //             apply((p>>h)<<1,lz[p>>h],1<<(h-1));
    //             apply((p>>h)<<1|1,lz[p>>h],1<<(h-1));
    //             lz[p>>h]=0;
    //         }
    //     }
    // }
    // void built(ll p){while(p>1) {p>>=1;if(!lz[p])combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void apply(ll p,ll val,ll k){ t[p]+=k*val; if(p<n) lz[p]+=val; }
    // void pad(ll p,ll val) {for(t[p+=n-1]={val,max(0LL,val)};p;p>>=1)combine(t[p>>1],(p&1)?t[p^1]:t[p],p&1?t[p]:t[p^1]);}
    void pst(ll p,ll val){for(t[p+=n-1].val=val;p;p>>=1)combine(t[p>>1],t[p],t[p^1]);}
    // void rad(ll l,ll r,ll val){
    //     ll l0,r0,k;
    //     k=1,l0=l+=n-1,r0=r+=n-1;
    //     push(l0),push(r0);
    //     for(;l<=r;l>>=1,r>>=1,k<<=1){
    //         if(l&1) apply(l++,val,k);
    //         if(!(r&1)) apply(r--,val,k);
    //     }
    //     built(l0),built(r0);
    // }
    Node query(ll l,ll r){
        // push(l+=n-1),push(r+=n-1);
        Node ans(0);
        l+=n-1,r+=n-1;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1) ans=ans+t[l++];
            if(!(r&1)) ans=ans+t[r--];
        }
        return ans;
    }
};

constexpr ll mxN=1e5+1;
ll n,m,res;
vc<ll> adj[mxN],w(mxN);
void dfs(ll u=1,ll p=0,ll cur=0){
    if(w[u]) cur++;
    else cur=0;
    if(cur>m) return;
    if(adj[u].size()==1 && u>1) {res++; return;}
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        dfs(v,u,cur);
    }
}
void solve(){
    cin>>n>>m;
    forn(i,1,n+1)cin>>w[i];
    forn(i,1,n){
        ll x,y;
        cin>>x>>y;
        adj[x].emp(y),adj[y].emp(x);
    }
    res=0;
    dfs();
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



