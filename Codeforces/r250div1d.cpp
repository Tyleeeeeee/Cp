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
// ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=1e5+1;

class Node{
    public:
        ll v,mx;
        Node(){}
        Node(ll val,ll mX):v(val),mx(mX){}
        
        friend Node operator+(const Node &a,const Node &b){
            return {a.v+b.v,max(a.mx,b.mx)};
        }
};
ll n,m,a[mxN];
Node t[mxN<<2];
Node built(ll i=1,ll l=1,ll r=n){
    if(l==r){
        t[i]={a[l],a[l]};
        return t[i];
    }
    ll mid; mid=(r+l)>>1;
    return t[i]=built(i<<1,l,mid)+built(i<<1|1,mid+1,r);
}
void rad(ll tl,ll tr,ll val,ll i=1,ll l=1,ll r=n){
    if(t[i].mx<val) return;
    if(tl>r || tr<l || l>r) return;
    if(l==r){
        t[i].v%=val,t[i].mx%=val;
        return;
    }
    ll mid; mid=(r+l)>>1;
    rad(tl,tr,val,i<<1,l,mid);
    rad(tl,tr,val,i<<1|1,mid+1,r);
    t[i]=t[i<<1]+t[i<<1|1];
}
void pst(ll tp,ll val,ll i=1,ll l=1,ll r=n){
    if(l==r){
        t[i].v=t[i].mx=val;
        return ;
    }
    ll mid; mid=(r+l)>>1;
    if(tp<=mid) pst(tp,val,i<<1,l,mid);
    else pst(tp,val,i<<1|1,mid+1,r);
    t[i]=t[i<<1]+t[i<<1|1];
}
ll query(ll tl,ll tr,ll i=1,ll l=1,ll r=n){
    if(tl>r || tr<l || l>r) return 0;
    if(tl<=l && tr>=r) return t[i].v;
    ll mid; mid=(l+r)>>1;
    return query(tl,tr,i<<1,l,mid)+query(tl,tr,i<<1|1,mid+1,r);
}
void solve(istream &cin){
    cin>>n>>m;
    forn(i,1,n+1) cin>>a[i];
    built();
    while(m--){
        ll type; cin>>type;
        if(type==1){
            ll l,r; cin>>l>>r; cout << query(l,r) << '\n';
        }
        else if(type==2){
            ll l,r,x; cin>>l>>r>>x; rad(l,r,x);
        }
        else{
            ll k,x; cin>>k>>x; pst(k,x);
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
