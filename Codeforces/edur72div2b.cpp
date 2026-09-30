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
#define fr first
#define sc second
#define pb(x) push_back(x)
#define is(x) insert(x)
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

int main()
{
    fast_io;
    ll t,n,x,res,a,b,mx;
    cin>>t;
    while(t--&&cin>>n>>x){
        mx=0,res=inf;
        vector<pair<ll,ll>> a(n); for(auto&v:a) cin>>v.fr>>v.sc,mx=max(mx,v.fr);
        for(int q=0;q<n;++q){
            if((a[q].fr-a[q].sc<=0 && a[q].fr<x) || res==1) continue;
            res=(a[q].fr>=x?1:min(res,(ll)ceil((double)(x-mx)/(a[q].fr-a[q].sc))+1LL));
        }
        cout << (res==inf?-1:res) << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/











