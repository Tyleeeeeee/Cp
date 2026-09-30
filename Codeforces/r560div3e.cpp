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
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll q=i;q<n;++q) cerr << name[q] << " \n"[q==n-1] //i<= <n
#else
    #define debug(x)
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll MAX5=100001; //1e5+1
constexpr ll MAX9=1000000001; //1e9+1
constexpr ll MAX6=1000001; //1e6+1
#define all(name) name.begin(),name.end()
#define pb(x) push_back(x)
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

int main()
{
    fast_io;
    ll n,res;
    cin>>n;
    vector<ll> a(n),b(n); for(ll q=0;q<n;++q) cin>>a[q],a[q]=(a[q]*(q+1)*(n-q)); for(auto&v:b) cin>>v;
    sort(all(a)),sort(all(b),[](ll c,ll d){return c>d;});
    res=0;
    for(int q=0;q<n;++q){
        a[q]%=mdl2,res=(res%mdl2+((a[q]*b[q])%mdl2))%mdl2;
    }
    cout << res%mdl2 << "\n";
    return 0; 
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/











