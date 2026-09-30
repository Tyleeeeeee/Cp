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
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
    #define TEST cerr << "test" << "\n"
#else
    #define debug(x)
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll mx5=100001; //1e5+1
constexpr ll mx9=1000000001; //1e9+1
constexpr ll mx6=1000001; //1e6+1
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define pb push_back
#define vc vector
#define ar array
#define uno unordered_map
#define pr pair
#define bg begin
#define ed end
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b){return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c){return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b){return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c){return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bct(T a){return bitset<64>(a).count();}
template<typename T> inline T fsp(T a,T b){ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;}

int main()
{
    fast_io;
    ll n,m,ok;
    vc<pr<ll,pr<ll,ll>>> ans;
    char c;
    cin>>n>>m;
    ll a[n+1][m+1]; for(int q=1;q<=n;++q) for(int w=1;w<=m;++w) cin>>c,a[q][w]=c=='*'?1:0;
    for(int q=1;q<=n;++q){
        for(int w=1;w<=m;++w){
            if(!a[q][w]) continue;
            ll k=0;
            while((q+k+1<=n && a[q+k+1][w]) && (q-k-1>0 && a[q-k-1][w]) && (w+k+1<=m && a[q][w+k+1]) && (w-k-1>0 && a[q][w-k-1])) ++k;
            if(k) {
                    for(int i=0;i<=k;++i) a[q+i][w]++,a[q-i][w]++,a[q][w+i]++,a[q][w-i]++;
                    ans.pb({k,{q,w}});
            }
        }
    }
    ok=1;
    for(int q=1;q<=n;++q) for(int w=1;w<=m;++w) if(a[q][w]==1) ok=0;
    cout << (ok?(ll)ans.size():-1) << "\n";
    if(ok) for(int q=0;q<ans.size();++q) cout << ans[q].sc.fr << " " << ans[q].sc.sc << " " << ans[q].fr << "\n";
    return 0;
}

