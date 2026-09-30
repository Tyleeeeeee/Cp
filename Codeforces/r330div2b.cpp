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
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
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
template<typename T> inline T add(T a,T b){return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c){return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b){return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c){return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bitcount(T a){return bitset<64>(a).count();}

int main()
{
    fast_io;
    auto f=[](ll a,ll b){
        ll ans=1;
        while(b){
            if(b&1) ans*=a;
            a*=a,b/=2;
        }
        return ans;
    };
    ll n,k,res;
    cin>>n>>k,res=1;
    vector<ll> a(n/k),b(n/k); for(auto&v:a)cin>>v; for(auto&v:b)cin>>v;
    for(int q=0;q<n/k;++q){
        ll x,y,z;
        x=(f(10,k)-1)/a[q]+1,y=((b[q]+1)*f(10,k-1)-1)/a[q]+!b[q],z=(b[q]*(f(10,k-1))-1*(b[q]>0))/a[q];
        res=(y==z?mul(res,x):mul(res,x-y+z));
    }
    cout << res%mdl1 << "\n";
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



