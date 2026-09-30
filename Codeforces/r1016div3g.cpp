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
 
constexpr ll mxN=7e6+1;
ll n,k,sz,t[mxN][2],cnt[mxN];
void insert(ll x){
    ll v; v=0;
    forr(i,30,0){
        if(t[v][(x>>i)&1]==-1) t[v][(x>>i)&1]=++sz;
        v=t[v][(x>>i)&1],cnt[v]++;
    }
}
void rm(ll x){
    ll v; v=0;
    forr(i,30,0){
        ll pre; pre=v;
        v=t[v][(x>>i)&1],cnt[v]--;
        if(!cnt[v]) t[pre][(x>>i)&1]=-1;
    }
}
ll query(ll x){
    ll ans,v; v=ans=0;
    forr(i,30,0){
        ll u; u=(x>>i)&1;
        if(t[v][u^1]!=-1) ans+=(1<<i);
        v=(t[v][u^1]!=-1?t[v][u^1]:t[v][u]);
    }
    return ans;
}
void solve(istream &cin){
    cin>>n>>k;
    if(!k){forn(i,1,n+1){ll x; cin>>x;}cout << 1 << '\n'; return;}
    memset(t,-1,8*64*n),memset(cnt,0,8*32*n);
    ll res,l;
    vc<ll> a(n+1);
    sz=0,l=1,res=inf;
    forn(i,1,n+1){
        cin>>a[i];
        if(i==1){insert(a[i]); continue;}
        ll ok; ok=0;
        while(l<i && query(a[i])>=k) ok=1,rm(a[l++]);
        if(ok) res=min(res,i-l+2);
        insert(a[i]);
    }
    cout << (res==inf?-1:res) << '\n';
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
