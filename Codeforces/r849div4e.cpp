#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    long long t,n,sum,dp[200001][2];
    cin>>t;
    while(t-- && cin>>n)
    {
        sum=0;
        memset(dp,0,sizeof(dp));
        long long arr[n];
        for(auto&v:arr)cin>>v,sum+=v;
        dp[n-1][0]=sum;
        dp[n-1][1]=sum-2*(arr[n-2]+arr[n-1]);
        for(int q=n-3;q>=0;--q)
        {
            dp[q+1][0]=max(dp[q+2][0],dp[q+2][1]);
            dp[q+1][1]=max(dp[q+2][0]-2*(arr[q+1]+arr[q]),dp[q+2][1]-2*arr[q]+2*arr[q+1]);
        }
        cout << (dp[1][0]>dp[1][1]?dp[1][0]:dp[1][1]) << "\n";
    }
}

