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

ll n,res,a[MAX5],b[MAX5],dp[MAX5][2];
int main()
{
    fast_io;
    cin>>n;
    for(int q=0;q<n;++q)cin>>a[q],b[q]=(q?abs(a[q]-a[q-1]):0);
    dp[1][0]=b[1],dp[1][1]=0;
    for(int q=2;q<n;++q){
        dp[q][0]=max(dp[q-1][1]+b[q],b[q]);
        dp[q][1]=dp[q-1][0]-b[q];
    }
    res=-1*inf;
    for(int q=1;q<n;++q)
        res=max(res,max(dp[q][0],dp[q][1]));
    cout << res << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



