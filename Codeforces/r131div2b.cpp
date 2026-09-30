 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Happy new year 2025
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
#define uns unordered_set
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
    vc<ll> zf(string &s){//z function
    ll n,lb,rb;
    n=s.length(),lb=rb=0;
    vc<ll> z(n,0);
    forn(i,1,n){
        if(z[i]<rb) z[i]=min(z[i-lb],max(rb-i,0LL));
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]>rb) lb=i,rb=i+z[i];
    }
    return z;
    }
    class gtr{public:bool operator()(char a,char b)const{return a>b;}};
    class lss{public:bool operator()(pll a,pll b)const{if(a.fr!=b.fr)return a.fr<b.fr; else return a.sc<b.sc;}};
}
class Node{
    public:
        ll val;
    
    Node(){}
    Node(ll v):val(v){}
    friend Node operator+(const Node&a,const Node&b){
        return {a.val+b.val};
    }
};

class Trie{
    public:
        ll sz=0;
        vc<vc<ll>> t;
        vc<ll> en;
 
    Trie(){}
    Trie(ll size):en(size+1,0),t(size+1,vc<ll>(3,-1)){}
    void insert(const string &s){
        ll v;
        v=0;
        for(auto&c:s){
            if(t[v][c-'a']==-1) t[v][c-'a']=++sz;
            v=t[v][c-'a'];
        }
        en[s.length()]++;
    }
    bool query(ll v,ll i,ll cnt,const string &s){
        if(cnt>1) return false;
        if(i==s.length()) return (cnt && en[i]);
        forn(j,0,3){
            if(t[v][j]==-1) continue;
            if(j!=s[i]-'a' && query(t[v][j],i+1,cnt+1,s)) return true;
            if(j==s[i]-'a' && query(t[v][j],i+1,cnt,s)) return true;
        }
        return false;
    }
};
class Segt{
    private:
    ll n;
    vc<Node> t;
    vc<ll> lz;
 
    public:
    Segt(){}
    Segt(ll size):n(size),t(2*size+5,0),lz(size+1,0){}
    Node &operator[](int i){ return t[i]; }
    void combine(Node &p,Node &l,Node &r){p=l+r;}
    void built(){ forr(i,n-1,1) combine(t[i],t[i<<1],t[i<<1|1]);}
    void apply(ll p,ll val,ll k){ if(p>=n) t[p].val^=val; if(p<n) lz[p]^=val,t[p].val=k-t[p].val; }
    void push(ll p){
        for(ll h=TLX::msb(n);h;h--){
            if(lz[p>>h]){
                apply((p>>h)<<1,lz[p>>h],1<<(h-1));
                apply((p>>h)<<1|1,lz[p>>h],1<<(h-1));
                lz[p>>h]=0;
            }
        }
    }
    // void built(ll p){while(p>1){p>>=1,combine(t[p],t[p<<1],t[p<<1|1]);}}
    void built(ll p){while(p>1) {p>>=1;if(!lz[p])combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void pad(ll p,ll val) {for(t[p+=n-1].val+=val;p;p>>=1)combine(t[p>>1],t[p],t[p^1]);}
    // void pst(ll p,ll val){
    //     push(p+=n-1);
    //     for(t[p].val=val;p;p>>=1)combine(t[p>>1],(p&1?t[p^1]:t[p]),p&1?t[p]:t[p^1]);
    // }
    void rad(ll l,ll r,ll val){
        ll l0,r0,k;
        k=1,l0=l+=n-1,r0=r+=n-1;
        push(l0),push(r0);
        for(;l<=r;l>>=1,r>>=1,k<<=1){
            if(l&1) apply(l++,val,k);
            if(!(r&1)) apply(r--,val,k);
        }
        built(l0),built(r0);
    }
    Node query(ll l,ll r){
        push(l+=n-1),push(r+=n-1);
        Node ans(0);
        // l+=n-1,r+=n-1;
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
        // ll query(ll p){return -pa[find(p)];}
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
    ll n,s,ok;
    cin>>n;
    vc<ll> a(n+1);
    map<ll,ll> zero,one,two;
    s=ok=0;
    forn(i,1,n+1){
        cin>>a[i];
        s+=a[i];
        if(!a[i]) ok=1;
        if(a[i]%3==0) zero[a[i]]++;
        if(a[i]%3==1) one[a[i]]++;
        if(a[i]%3==2) two[a[i]]++;
    }
    if(!ok){cout << -1 << '\n'; return;}
    if(s%3){
        if(s%3==1){
            if(!one.empty()){ (one.bg()->sc)--; if(!(one.bg()->sc)) one.erase(one.bg());}
            else{
                (two.bg()->sc)--;
                if(!(two.bg()->sc)) two.erase(two.bg()->fr);
                if(!two.empty()){(two.bg()->sc)--; if(!(two.bg()->sc))two.erase(two.bg());}
            }
        }
        else{
            if(!two.empty()){ (two.bg()->sc)--; if(!(two.bg()->sc))two.erase(two.bg());}
            else{
                (one.bg()->sc)--;
                if(!(one.bg()->sc)) one.erase(one.bg()->fr);
                if(!one.empty()){ (one.bg()->sc)--; if(!(one.bg()->sc))one.erase(one.bg());}
            }
        }
    }
    string res;
    for(auto&v:zero){
        if(!v.fr && zero.size()==1 && !one.size() && !two.size()){res+='0'; continue;}
        forn(i,0,v.sc) res+=v.fr+'0';
    } 
    for(auto&v:one) forn(i,0,v.sc) res+=v.fr+'0';
    for(auto&v:two) forn(i,0,v.sc) res+=v.fr+'0';
    sort(all(res),gtr());
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

