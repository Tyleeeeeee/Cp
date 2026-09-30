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
 
//0=L 1=D 2=R 3=U
// ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};

constexpr ll mxN=4e5+1;
ll n,m,t[mxN],lz[mxN],res;
ll msb(ll x){forr(i,30,0) if(x&(1<<i)) return i; return -1;}
void apply(ll p,ll val,ll k){
    t[p]+=k*val;
    if(p<n) lz[p]+=val;
}
void built(ll p){
    while(p>>=1){
        if(!lz[p]) t[p]=t[p<<1]+t[p<<1|1];
    }
}
void push(ll p){
    for(ll h=msb(n);h;h--){
        if(lz[p>>h]){
            apply((p>>h)<<1,lz[p>>h],1<<(h-1));
            apply((p>>h)<<1|1,lz[p>>h],1<<(h-1));
            lz[p>>h]=0;
        }
    }
}
void rad(ll l,ll r,ll val){
    ll l0,r0,k;
    l0=l+n-1,r0=r+n-1,k=1;
    push(l0),push(r0);
    for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1,k<<=1){
        if(l&1) apply(l++,val,k);
        if(!(r&1)) apply(r--,val,k);
    }
    built(l0),built(r0);
}
ll query(ll l,ll r){
    ll res; res=0;
    push(l+=n-1),push(r+=n-1);
    for(;l<=r;l>>=1,r>>=1){
        if(l&1) res+=t[l++];
        if(!(r&1)) res+=t[r--];
    }
    return res;
}
void solve(istream &cin){
    cin>>n>>m;
    res=0;
    forn(i,1,n+1) t[i]=t[i+n]=lz[i]=0;
    forn(i,1,m+1){
        ll x; cin>>x;
        res+=query(max(1LL,n-x),n-1);
        rad(1,x,1);
    }
    cout << (res<<1) << '\n';
}
int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

