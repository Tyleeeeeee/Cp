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
    using namespace std;
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
    class lss{public:bool operator()(ll a,ll b)const{return a<b;}};
}
class Node{
    public:
    ll val;
    Node(){}
    Node(ll v):val(v){}
    friend Node operator+(const Node&a,const Node&b){
        return max(a.val,b.val);
    }
    
};
class TrieNode{
    public:
        ll val;
        TrieNode* leftPtr;
        TrieNode* rightPtr; 
        TrieNode():leftPtr(nullptr),rightPtr(nullptr){}
        TrieNode(ll v):val(v),leftPtr(nullptr),rightPtr(nullptr){}
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
            if(!p) return;
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
    // void built(ll p){while(p>1){p>>=1,combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void built(ll p){while(p>1) {p>>=1;if(!lz[p])combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void apply(ll p,ll val,ll k){ t[p]+=k*val; if(p<n) lz[p]+=val; }
    // void pad(ll p,ll val) {for(t[p+=n-1].val+=val;p;p>>=1)combine(t[p>>1],t[p],t[p^1]);}
    // void pst(ll p,ll val){for(t[p+=n-1].val=val;p;p>>=1)combine(t[p>>1],(p&1?t[p^1]:t[p]),p&1?t[p]:t[p^1]);}
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
        if(l>r) return {-inf};
        // push(l+=n-1),push(r+=n-1);
        Node ans(0);
        l+=n-1,r+=n-1;
        for(;l<=r;l>>=1,r>>=1){
            if(l&1LL) ans=ans+t[l++];
            if(!(r&1LL)) ans=ans+t[r--];
        }
        return ans;
    }
};
class Trie{
    private:
        TrieNode *root;//TrieNode

    public:
        Trie(){this->root=new TrieNode(1);}
        void insert(ll x){
            TrieNode *cur=root;
            forr(i,30,0){
                ll val;
                val=(1<<i) & x;
                if(!val){
                    // err(i,x,val,"Left");
                    if(cur->leftPtr==nullptr) cur->leftPtr=new TrieNode(1);
                    else (cur->leftPtr->val)++;
                    cur=cur->leftPtr;
                }
                else{
                    // err(i,x,val,"right");
                    if(cur->rightPtr==nullptr) cur->rightPtr=new TrieNode(1);
                    else (cur->rightPtr->val)++;
                    cur=cur->rightPtr;
                }
            }
        }
        void deleted(ll x){
            TrieNode *cur=root;
            forr(i,30,0){
                ll val;
                val=(1<<i) & x;
                if(!val) cur=cur->leftPtr;
                else cur=cur->rightPtr;
                (cur->val)--;
            }
        }
        ll query(ll x){
            ll res;
            TrieNode *cur=root;
            res=0;
            forr(i,30,0){
                ll val;
                val=(1<<i) & x;
                if(!val){
                    if(cur->rightPtr!=nullptr && cur->rightPtr->val){
                        res+=(1<<i);
                        cur=cur->rightPtr;
                    }
                    else if(cur->leftPtr!=nullptr && cur->leftPtr->val){
                        cur=cur->leftPtr;
                    }
                }
                else{
                    if(cur->leftPtr!=nullptr && cur->leftPtr->val){
                        res+=(1<<i);
                        cur=cur->leftPtr;
                    }
                    else if(cur->rightPtr!=nullptr && cur->rightPtr->val){
                        cur=cur->rightPtr;
                    }
                }
            }
            return res;
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
// constexpr ll mxN=2500+1;
// vc<ll> dx({-1,0,1,0}),dy({0,-1,0,1}),P(mxN,0);
// vc<char> dir({'U','L','D','R'});
ll n;
void solve(vc<ll> &a,vc<ll> &left,vc<ll> &right){
    stack<ll> c,d;
    forn(i,1,n+1){
        while(!c.empty() && a[c.top()]<a[i]){
            right[c.top()]=i;
            c.pop();
        }
        c.push(i);
    }
    swap(c,d);
    forr(i,n,1){
        while(!c.empty() && a[c.top()]<a[i]){
            left[c.top()]=i;
            c.pop();
        }
        c.push(i);
    }
}
void solve(){
    cin>>n;
    vc<ll> a(n+1);
    forn(i,1,n+1) cin>>a[i];
    vc<ll> pfx(n+1),sfx(n+1);
    pfx[0]=0,sfx[n]=a[n];
    forn(i,1,n+1){
        pfx[i]=pfx[i-1]+a[i];
        sfx[n-i]=sfx[n-i+1]+a[n-i];
    }
    vc<ll> right(n+1,inf),left(n+1,-1),pright(n+1,inf),pleft(n+1,-1),sright(n+1,inf),sleft(n+1,-1);
    solve(a,left,right),solve(pfx,pleft,pright),solve(sfx,sleft,sright);
    forn(i,1,n+1){
        if(i<n &&  pright[i]<right[i]){cout << "NO" << '\n'; return;}
        if(i>1 && sleft[i]>left[i]){cout << "NO" << '\n';return;}
    }
    cout << "YES" << '\n';
}
int main()
{
    fast_io;
    ll t;
    cin>>t;
    // t=1;
    while(t--)
        solve();
    return 0;
}









