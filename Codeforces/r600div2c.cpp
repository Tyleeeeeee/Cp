#include<iostream>
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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,m;
int main()
{
    fast_io;
    cin>>n>>m;
    ll arr[n+1],dp[n+1],sum;
    for(int q=1;q<=n;++q)cin>>arr[q];
    sort(arr+1,arr+n+1);
    memset(dp,0,sizeof(dp));
    sum=0,sum+=(dp[1]=arr[1]);
    for(int q=2;q<=n;++q){
        //   without penatly    with penatly
        //dp[q]=sum+arr[q]   +  dp[q-m]
        dp[q]=(q<=m?dp[q-1]+arr[q]:sum+arr[q]+dp[q-m]);
        sum+=arr[q];
    }
    for(int q=1;q<=n;++q) cout << dp[q] << " ";
    cout << "\n";
}
/*
   author :tlx
               */

