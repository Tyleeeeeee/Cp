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

ll n,x;
int main()
{
    fast_io;
    cin>>n>>x;
    vector<ll> a(n); for(auto&v:a)cin>>v;
    sort(a.begin(),a.end());
    ll lp,rp,res;
    res=0;
    for(lp=0,rp=n-1;rp>=0 && lp<=rp;rp--){
        if(a[lp]+a[rp]<=x) lp++;
        res++;
    }
    cout << res << "\n";
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/





