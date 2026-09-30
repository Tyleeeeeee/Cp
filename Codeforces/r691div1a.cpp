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
#define pb(x) push_back(x)
#define is(x) insert(x)
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}

int main()
{
    fast_io;
    ll n,m,x,rc;
    cin>>n>>m;
    vector<ll> a(n),b(m); for(auto&v:a)cin>>v; for(auto&v:b)cin>>v;
    x=0;
    for(int q=1;q<n;++q){
        x=gcd(x,abs(a[q]-a[0]));
    }
    for(int q=0;q<m;++q){
        cout << gcd(x,a[0]+b[q]) << " \n"[q==m-1];
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/











