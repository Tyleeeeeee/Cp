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
            if(i<rb) z[i]=min(z[i-lb],max(rb-i,0LL));
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
        ll v;
    
    Node(){}
    Node(ll V):v(V){}
    friend Node operator+(const Node&a,const Node&b){
        return min(a.v,b.v);
    }
};
class Segt{
    private:
    ll n;
    vc<Node> t;
    // vc<ll> lz;
 
    public:
    Segt(){}
    Segt(ll size):n(size),t(2*size+5){}
    // Segt(ll size):n(size),t(2*size+5,0),lz(size+1,0){}
    Node &operator[](int i){ return t[i]; }
    void combine(Node &p,Node &l,Node &r){p=l+r;}
    void built(){ forr(i,n-1,1) combine(t[i],t[i<<1],t[i<<1|1]);}
    // void apply(ll p,ll val,ll k){ if(p>=n) t[p].val^=val; if(p<n) lz[p]^=val,t[p].val=k-t[p].val; }
    // void push(ll p){
    //     for(ll h=TLX::msb(n);h;h--){
    //         if(lz[p>>h]){
    //             apply((p>>h)<<1,lz[p>>h],1<<(h-1));
    //             apply((p>>h)<<1|1,lz[p>>h],1<<(h-1));
    //             lz[p>>h]=0;
    //         }
    //     }
    // }
    // void built(ll p){while(p>1){p>>=1,combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void built(ll p){while(p>1) {p>>=1;if(!lz[p])combine(t[p],t[p<<1],t[p<<1|1]);}}
    // void pad(ll p,ll val) {for(t[p+=n-1].val+=val;p;p>>=1)combine(t[p>>1],t[p],t[p^1]);}
    // void pst(ll p,ll val){
    //     // push(p+=n-1);
    //     ll x; x=p;
    //     p+=n-1;
    //     t[p].vl=val-x,t[p].vr=val+x;
    //     for(;p;p>>=1)combine(t[p>>1],(p&1?t[p^1]:t[p]),p&1?t[p]:t[p^1]);
    // }
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
        Node ans(inf);
        l+=n-1,r+=n-1;
        for(;l<=r;l>>=1,r>>=1){
            // err(l,r,t[l].v,t[r].v);
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
// class node{
//     public:
//         int len,link,cnt,fp,next[26];
// };
// constexpr int mxN=1e5+1;
// int sz,k,n,d[2*mxN];
// node tr[2*mxN];
// void sfa(const string &s){
//     int ls,cur;
//     sz=ls=cur=0;
//     memset(tr,0,sizeof(tr));
//     tr[sz].len=0,tr[sz].link=-1,tr[sz].cnt=1;
//     for(auto&v:s){
//         cur=++sz;
//         tr[cur].len=tr[ls].len+1,tr[cur].cnt=1,tr[cur].fp=tr[ls].len+1;
//         int p; p=ls; 
//         while(p!=-1 && !tr[p].next[v-'a']) tr[p].next[v-'a']=cur,p=tr[p].link;
//         if(p==-1) tr[cur].link=0;
//         else{
//             int q; q=tr[p].next[v-'a'];
//             if(tr[p].len+1==tr[q].len) tr[cur].link=q;
//             else{
//                 int clone; clone=++sz;
//                 tr[clone].len=tr[p].len+1,tr[clone].link=tr[q].link,tr[clone].fp=tr[q].fp;
//                 memcpy(tr[clone].next,tr[q].next,sizeof(tr[q].next));
//                 while(p!=-1 && tr[p].next[v-'a']==q) tr[p].next[v-'a']=clone,p=tr[p].link;
//                 tr[q].link=tr[cur].link=clone;
//             }
//         }
//         ls=cur;
//     }
// }
// constexpr int mxN=2e5+1;
// ll g,n,p[mxN],c[mxN],lcp[mxN];
// bool comp(int a,int b){
//     if(c[a]!=c[b]) return c[a]<c[b];
//     a+=g,b+=g;
//     return (a<n && b<n) ? c[a]<c[b] : a>b;
// }
// void sfxa(const string &s){
//     int tmp[n]; tmp[0]=0;
//     forn(i,0,n) p[i]=i,c[i]=s[i];
//     for(g=1;;g<<=1){
//         sort(p,p+n,comp);
//         forn(i,0,n-1) tmp[i+1]=tmp[i]+comp(p[i],p[i+1]);
//         forn(i,0,n) c[p[i]]=tmp[i];
//         if(tmp[n-1]==n-1) break;
//     }
// }
// void Lcp(const string &s){
//     int k; k=0;
//     forn(i,0,n){
//         if(c[i]!=n-1){
//             int j; j=p[c[i]+1];
//             while(j+k<n && i+k<n && s[i+k]==s[j+k]) k++;
//             lcp[c[i]]=k;
//             if(k) k--;
//         }
//     }
// }
// constexpr ll mxN=1e6+1;
// ll pdl[mxN][2];
// void Pdl(const string &s){
//     for(ll i=0,l1=0,l2=0,r1=-1,r2=-1;i<s.length();++i){
//         ll k1,k2; 
//         k1=(i>r1?1:min(pdl[l1+r1-i][1],r1-i+1)),k2=(i>r2?0:min(pdl[l2+r2-i+1][0],r2-i+1));
//         while(i-k1>=0 && i+k1<s.length() && s[i-k1]==s[i+k1]) k1++; pdl[i][1]=--k1;
//         while(i-k2-1>=0 && i+k2<s.length() && s[i-k2-1]==s[i+k2]) k2++; pdl[i][0]=k2--;
//         if(i+k1>r1) l1=i-k1,r1=i+k1;
//         if(i+k2>r2) l2=i-k2-1,r2=i+k2;
//     }
// }
constexpr int mxN=8e6+1;
int tr[mxN][2],sz;
void insert(int x){
    int v; v=0;
    for(int i=29;i>=0;--i){
        if(tr[v][!!(x&(1<<i))]==-1) tr[v][!!(x&(1<<i))]=++sz;
        v=tr[v][!!(x&1<<i)];
    }
}
int query(int x){
    int v; v=0;
    for(int i=29;i>=0;--i){
        ll k;
        k=(x>>i)&1;
        if(tr[v][k^1]!=-1) k^=1;
        x^=(k<<i);
        v=tr[v][k];
    }
    return x;
}
void solve(){
    int n;
    cin>>n;
    vc<int> a(n),res;
    sz=a[0]=0;
    memset(tr,-1,sizeof(tr));
    insert(0);
    forn(i,1,n) cin>>a[i],a[i]^=a[i-1],insert(a[i]);
    for(int i=0;i<n;++i){
        if(query(i)==n-1){
            for(int j=0;j<n;++j) res.emp(i^a[j]);
            break;
        }
    }
    for(auto&v:res) cout << v << ' ';
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

