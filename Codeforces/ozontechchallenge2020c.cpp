#include<iostream>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
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
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cout << name << ":" << x << "\n"
    #define debugr(name,i,n) for(ll q=i;q<n;++q) cout << name[q] << " \n"[q==n-1] //i<= <n
#else
    #define debug(x)
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX5 100001 //1e5+1
#define MAX9 1000000001 //1e9+1
#define MAX6 1000001 //1e6+1
#define all(name) name.begin(),name.end()
#define pb(x) push_back(x)
#define is(x) insert(x)
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

int main()
{
    fast_io;
    ll n,m,res;
    cin>>n>>m;
    vector<ll> a(n); for(auto&v:a)cin>>v;
    res=1;
    if(n>m) res=0;
    else for(int q=0;q<n && res;++q) for(int w=q+1;w<n && res;++w) res=(res*abs(a[q]-a[w]))%m;
    cout << res << "\n";
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/











