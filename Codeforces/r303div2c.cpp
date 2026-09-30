#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll=long long;

ll n,arr[100000][2],dp[100000][2],ans;
int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    cin>>n;
    for(int q=0;q<n;++q) cin>>arr[q][0]>>arr[q][1];
    ans=0;
    memset(dp,0,sizeof(dp));
    ans=max(ans,max(dp[0][0]=1,dp[0][1]=(arr[0][0]+arr[0][1])<arr[1][0]));
    for(int q=1;q<n;++q){
        if(arr[q][0]-arr[q][1]<=arr[q-1][0]) dp[q][0]=max(dp[q-1][0],dp[q-1][1]);
        else if(arr[q][0]-arr[q][1]>arr[q-1][0]+arr[q-1][1]) dp[q][0]=max(dp[q-1][0],dp[q-1][1])+1;
        else dp[q][0]=dp[q-1][0]+1;
        if(q<n-1){
            if(arr[q][0]+arr[q][1]>=arr[q+1][0]) dp[q][1]=max(dp[q-1][0],dp[q-1][1]);
            else if(arr[q][0]+arr[q][1]<arr[q+1][0]-arr[q+1][1]) dp[q][1]=max(dp[q-1][0],dp[q-1][1])+1;
            else dp[q][1]=max(dp[q-1][0],dp[q-1][1])+1;
        }
        else dp[q][1]=max(dp[q-1][0],dp[q-1][1])+1;
        ans=max(ans,max(dp[q][0],dp[q][1]));
    }
    cout << ans << "\n";
}

