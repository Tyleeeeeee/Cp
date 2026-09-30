#include<iostream>
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

ll n,dp[200001];
int main()
{
    fast_io;
    auto finv=[](ll a,ll m){
        ll ans=1;
        while(m){
            if(m&1) ans=(ans*a)%mdl2;
            a=(a*a)%mdl2,m/=2;
        }
        return ans;
    };
    cin>>n;
    ll sum1,sum2;
    sum1=1,sum2=0;
    dp[1]=1;
    for(int q=2;q<=n;++q){
        dp[q]=(q&1?sum2+1:sum1)%mdl2;
        sum1+=(q&1?dp[q]:0)%mdl2,sum2+=(q&1?0:dp[q])%mdl2;
    }
    cout << ((dp[n]%mdl2)*(finv(2,n*(mdl2-2))%mdl2))%mdl2 << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



