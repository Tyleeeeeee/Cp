#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t,n,max,dp[200001];
    cin>>t;
    while(t-- && cin>>n)
    {
        memset(dp,0,sizeof(dp));
        long long arr[n];
        for(auto&v:arr) cin>>v;
        max=dp[n]=arr[n-1];
        for(int q=n-2;q>=0;--q)
        {
            if(q+arr[q]<=n-1) dp[q+1]=dp[q+arr[q]+1]+arr[q];
            else dp[q+1]=arr[q];
            max=(dp[q+1]>max?dp[q+1]:max);
        }
        cout << max << "\n"; 
    }
}

