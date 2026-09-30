#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int n,m,a,i,j;
    cin>>n;
    long long arr[n],dp[2][n+1],srt[n],ans;
    memset(dp,0,sizeof(dp));
    for(int q=0;q<n;++q)
    {
        cin>>arr[q],srt[q]=arr[q];
        if(!q) dp[0][q+1]=arr[q];
        else dp[0][q+1]=dp[0][q]+arr[q];
    }
    sort(srt,srt+n);
    dp[1][1]=srt[0];
    for(int q=1;q<n;++q) dp[1][q+1]=dp[1][q]+srt[q];
    cin>>m; 
    for(int q=0;q<m;++q)
    {
        ans=0;
        cin>>a>>i>>j;
        cout << (a==1?dp[0][j]-dp[0][i-1]:dp[1][j]-dp[1][i-1]) << "\n";
    }
}

