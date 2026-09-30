 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
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
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ii=int;
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
#define pii pr<ii,ii>
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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=1e6+1;
class Node{
    public:
        ll n4,n7,n47,n74;
        Node(){}
        Node(ll N4,ll N7,ll N47,ll N74):n4(N4),n7(N7),n47(N47),n74(N74){}
        friend Node operator+(const Node &a,const Node&b){
            return {a.n4+b.n4,a.n7+b.n7,max({a.n47+b.n7,a.n4+b.n47,a.n4+b.n7}),max({a.n74+b.n4,a.n7+b.n74,a.n7+b.n4})};
        }
};
ll n,m,lz[mxN]={0};
Node t[mxN<<1];
ll msb(ll x){forr(i,30,0) if((x>>i)&1) return i; return -1;}
void built(){forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];}
void apply(ll p){swap(t[p].n4,t[p].n7),swap(t[p].n47,t[p].n74); if(p<n) lz[p]^=1;}
void push(ll p){
    for(ll h=msb(n);h;h--){
        if(lz[p>>h]){
            apply((p>>h)<<1);
            apply((p>>h)<<1|1);
            lz[p>>h]=0;
        }
    }
}
void built(ll p){while(p>>=1) if(!lz[p]) t[p]=t[p<<1]+t[p<<1|1];}
void rad(ll l,ll r){
    ll L,R; L=l+=n-1,R=r+=n-1;
    push(L),push(R);
    for(;l<=r;l>>=1,r>>=1){
        if(l&1) apply(l++);
        if(!(r&1)) apply(r--);
    }
    built(L),built(R);
}
Node query(ll l,ll r){
    push(l+=n-1),push(r+=n-1);
    Node pfx({0,0,0,0}),sfx({0,0,0,0});
    for(;l<=r;l>>=1,r>>=1){
        if(l&1) pfx=pfx+t[l++];
        if(!(r&1)) sfx=t[r--]+sfx;
    }
    return pfx+sfx;
}
void solve(istream &cin){
    cin>>n>>m;
    forn(i,1,n+1){
        char ch; cin>>ch;
        ll x; x=(ch=='7');
        t[i+n-1]={x^1,x,1,1};
    }
    built();
    // forn(i,1,2*n){err(i,t[i].n4,t[i].n7,t[i].n47,t[i].n74);}
    while(m--){
        string op; cin>>op;
        if(op=="count") cout << query(1,n).n47 << '\n';
        else{
            ll l,r; cin>>l>>r;
            rad(l,r);
            // forn(i,1,2*n){err(i,t[i].n4,t[i].n7,t[i].n47,t[i].n74);}
        }
    }
}

int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
