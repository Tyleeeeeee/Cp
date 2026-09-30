#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    long long n,dp[2][100000];
    cin>>n;

    long long arr[2][n],mx;
    for(int q=0;q<2;++q) for(int w=0;w<n;++w)cin>>arr[q][w];
    mx=0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=arr[0][0];
    dp[1][0]=arr[1][0];
    mx=max(mx,max(dp[0][0],dp[1][0]));
    for(int q=1;q<n;++q){
        dp[0][q]=max(arr[0][q]+dp[1][q-1],dp[0][q-1]);
        dp[1][q]=max(arr[1][q]+dp[0][q-1],dp[1][q-1]);
        mx=max(mx,max(dp[0][q],dp[1][q]));
    }
    cout << mx << "\n";
}


