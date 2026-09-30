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

ll t,n,a[200001],dp[200001][1<<2];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        for(int q=1;q<=n;++q) cin>>a[q];
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        //q&1 1=even 0=odd
        for(int q=1;q<=n;++q){
            dp[q][0]=dp[q-1][0]+(q&1?a[q]:0);
            dp[q][1]=(q-2>=0)*(max(dp[q-2][0],dp[q-2][1])+((q-1)&1?a[q]:a[q-1]));
            dp[q][2]=max(dp[q-1][0],max(dp[q-1][1],dp[q-1][2]))+(q&1?a[q]:0);
        }
        cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



