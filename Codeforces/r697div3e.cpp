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

int main()
{
    fast_io;
    ll t,n,k,res;
    // nCr=n-1Cr+ n-1Cr-1
    vector<vector<ll>> C(1001,vector<ll>(1001,0));
    C[0][0]=1;
    for(int q=1;q<1001;++q){
        for(int w=0;w<=q;++w){
            C[q][w]=(!w?1:C[q-1][w]+C[q-1][w-1])%mdl1;
        }
    }
    cin>>t;
    while(t--&&cin>>n>>k){
        unordered_map<ll,ll> mp;
        vector<ll> a(n); for(auto&v:a)cin>>v,mp[v]++;
        sort(a.begin(),a.end(),[](ll a,ll b){return a>b;});
        if(k<n && a[k]==a[k-1]){
            //mp[a[k-1]]Cx;
            ll x=k-(lower_bound(a.begin(),a.end(),a[k-1],[](ll c,ll d){return c>d;})-a.begin());
            res=C[mp[a[k-1]]][x];
        }
        else
            res=1;
        cout << res << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/











