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

void solve(istream &cin){
    ll n,m;
    cin>>n>>m;
    vc<ll> a(n),b(m);
    for(auto&v:a) cin>>v;
    for(auto&v:b) cin>>v;
    sort(all(a)),sort(all(b));
    vc<ll> pax,pbx;
    for(ll l=0,r=a.size()-1;l<r;l++,r--) pax.emp(a[r]-a[l]);
    for(ll l=0,r=b.size()-1;l<r;l++,r--) pbx.emp(b[r]-b[l]);
    partial_sum(all(pax),pax.bg());
    partial_sum(all(pbx),pbx.bg());
    ll k_max; k_max=min({n,m,(n+m)/3});
    cout << k_max << '\n';
    if(k_max){
        forn(i,1,k_max+1){
            ll L,R; L=max(0LL,2*i-m),R=min(i,n-i)+1;
            while(R-L>1){
                ll m1,m2;
                m1=L+(R-L)/3,m2=L+2*(R-L)/3;
                if((m1-1>=0?pax[m1-1]:0)+(i-m1-1>=0?pbx[i-m1-1]:0)>(m2-1>=0?pax[m2-1]:0)+(i-m2-1>=0?pbx[i-m2-1]:0)) R=m2;
                else L=m1+1;
            }
            cout << ((L-1>=0?pax[L-1]:0)+(i-L-1>=0?pbx[i-L-1]:0)) << " \n"[i==k_max];
        }
    }
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

