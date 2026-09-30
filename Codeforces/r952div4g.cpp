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
#define log2(x) (log(x)/log(2))

int main()
{
    fast_io;
    ll t,l,r,k,res;
    auto solve=[&k](ll a){
        ll ans,m;
        ans=1,m=a,a=9/k+1;
        while(m){
            if(m&1) ans=(ans*a)%mdl1;
            a=(a*a)%mdl1,m/=2;
        }
        ans=(ans-1+mdl1)%mdl1;
        return ans;
    };
    cin>>t;
    while(t--&&cin>>l>>r>>k){
        res=k>9?0:1;
        if(k<10) res=(solve(r)-solve(l)+mdl1)%mdl1;
        cout << res << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







