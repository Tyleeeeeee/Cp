#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int t,n,dp[200001];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>t;
    while(t--&&cin>>n){
        int arr[n];
        for(auto&v:arr)cin>>v;
        memset(dp,0,sizeof(dp));
        dp[n-1]=1;
        for(int q=n-2;q>=0;--q){
            if(q+arr[q]>n-1) dp[q]=1+dp[q+1];
            else dp[q]=min(1+dp[q+1],dp[q+arr[q]+1]);
        }
        cout << dp[0] << "\n";
    }
}

