#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[200001],t,n;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--&&cin>>n){
        int arr[n];
        for(int q=0;q<n;++q){
            cin>>arr[q];
        }
        int mx[n+1][2];
        memset(dp,0,sizeof(dp)),memset(mx,0,sizeof(mx));
        for(int q=0;q<n+1;++q) mx[q][1]=-1;
        dp[n-1]=0;
        mx[arr[n-1]][0]=0,mx[arr[n-1]][1]=n-1;
        for(int q=n-2;q>=0;--q){
            if(mx[arr[q]][1]!=-1) dp[q]=max(dp[q+1],mx[arr[q]][1]-q+1+mx[arr[q]][0]);
            else dp[q]=dp[q+1];
            if(mx[arr[q]][1]==-1) mx[arr[q]][0]=dp[q+1],mx[arr[q]][1]=q;
            else if(mx[arr[q]][0]+mx[arr[q]][1]-q<=dp[q+1]) mx[arr[q]][0]=dp[q+1],mx[arr[q]][1]=q;
        }
        cout << dp[0] << "\n";
    }
}

