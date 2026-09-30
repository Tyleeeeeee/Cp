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
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX5 100001 //1e5+1
#define MAX9 1000000001 //1e9+1
#define MAX6 1000001 //1e6+1
#define pb(x) push_back(x)
#define is(x) insert(x)

ll n,m,k,res;
int main()
{
    fast_io;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m); for(auto&v:a)cin>>v; for(auto&v:b)cin>>v;
    res=0;
    sort(b.begin(),b.end()); sort(a.begin(),a.end());
    ll w=0;
    for(ll q=0;q<n;++q){
        ll ok=1;
        for(;w<m && ok;++w){
            if(b[w]>a[q]+k) break;
            else if(b[w]>=a[q]-k) res++,ok=0;
        }
    }
    cout << res << "\n";
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/





