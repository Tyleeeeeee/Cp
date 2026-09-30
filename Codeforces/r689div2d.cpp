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
#define allb(name) name.begin(),name.begin()+n
#define pb(x) push_back(x)
#define vc vector
#define pr pair
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b){return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c){return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b){return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c){return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bitcount(T a){return bitset<64>(a).count();}

ll t,n,q,s,ok;
vc<ll> a(MAX5+1),pref(MAX5+1,0);
unordered_map<ll,ll> mp;
void solve(ll i,ll j){
    mp[pref[j]-pref[i-1]]++;
    if(i>=j) return;
    ll mid=(a[i]+a[j])/2;
    ll x=upper_bound(a.begin()+i,a.begin()+j+1,mid)-a.begin();
    if(x<=j) solve(i,x-1),solve(x,j);
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>q){
        mp.clear();
        for(int q=1;q<=n;++q) cin>>a[q];
        sort(1+allb(a)+1),partial_sum(1+allb(a)+1,pref.begin()+1),solve(1,n);
        while(q--&&cin>>s) cout << (mp[s]?"Yes":"No") << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/





