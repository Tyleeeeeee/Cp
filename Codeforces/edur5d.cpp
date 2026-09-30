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
    ll n,k,l,r,mx;
    cin>>n>>k,mx=0;
    vector<ll> a(n),b(MAX6,0); for(auto&v:a)cin>>v;
    for(ll lp=0,rp=0,sum=0;rp<n;++rp){
        sum+=!b[a[rp]],b[a[rp]]++;
        while(sum>k){
            sum-=!(b[a[lp]]-1),b[a[lp++]]--;
        }
        if(rp-lp+1>mx) l=lp+1,r=rp+1,mx=rp-lp+1;
    }
    cout << l << " " << r << "\n";
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



