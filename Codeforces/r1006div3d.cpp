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

constexpr ll mxN=2e3;
ll t[2*mxN];
void pad(ll p,ll val){
    for(t[p+=mxN-1]+=val;p>1;p>>=1){
        t[p>>1]=t[p]+t[p^1];
    }
}
ll query(ll l,ll r){
    if(r<l) return 0;
    ll ans; ans=0;
    for(l+=mxN-1,r+=mxN-1;l<=r;l>>=1,r>>=1){
        if(l&1) ans+=t[l++];
        if(!(r&1)) ans+=t[r--];
    }
    return ans;
}
void solve(istream &cin){
    ll n;
    cin>>n;
    vc<ll> a(n+1);
    forn(i,1,n+1)cin>>a[i];
    ll mx; mx=0;
    pll res; 
    forn(i,1,n+1){
        memset(t,0,sizeof(t));
        forn(j,i+1,n+1){
            pad(a[j],1);
            ll x,y;
            x=query(a[i]+1,2e3),y=query(1,a[i]-1);
            //x elements > a[i] mean increase inversion 
            //j-i total elements => j-i-x elements <= a[i] mean decrease inversion
            //j-i-2*x =0 mean nothing change >0 mean decrease  <0 mean increase
            if(y-x>mx) mx=y-x,res.fr=i,res.sc=j;
            // err(i,j,x,y,y-x,mx);
        }
    }
    cout << (mx?res.fr:1) << ' ' << (mx?res.sc:1) << '\n';
}
int main()
{
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

