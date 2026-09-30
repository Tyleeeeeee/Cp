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

ll n,dp[MAX6][1<<4];
int main()
{
    fast_io;
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int q=1;q<=n;++q){
        dp[q][0]=(dp[q-1][0]+(q&1?0:dp[q-1][1]+1))%mdl1;
        dp[q][1]=(dp[q-1][1]+(q&1?dp[q-1][0]:0))%mdl1;
        dp[q][2]=(dp[q-1][2]+(q&1?0:dp[q-1][3]))%mdl1;
        dp[q][3]=(dp[q-1][3]+(q&1?dp[q-1][2]+1:0))%mdl1;
    }
    cout << (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%mdl1 << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/

