#include<iostream>
#include<cstring>
using namespace std; 

int main()
{
    int t,n,k,ans,dp[200000];
    cin>>t;
    while(t--&&cin>>n>>k){ ans=0;
        long long arr[n];
        for(auto&v:arr)cin>>v;
        memset(dp,0,sizeof(dp));
        for(int q=n-2;q>=n-k;--q){
            dp[q]=dp[q+1]+(arr[q]/2 < arr[q+1]);
        }
        dp[n-k-1]=(arr[n-k-1]/2 < arr[n-k])+dp[n-k];
        for(int q=n-k-2;q>=0;--q){
            dp[q]=(arr[q]/2 < arr[q+1])+dp[q+1]-(arr[q+k]/2 < arr[q+k+1]);
        }
        for(int q=0;q<n-1;++q) ans+=(dp[q]==k);
        cout << ans << "\n";
    }
}

