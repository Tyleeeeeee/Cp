#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,dp[100][3];
    cin>>n;
    int arr[n];
    for(auto&v:arr)cin>>v;
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    dp[0][1]=(arr[0]%2);
    dp[0][2]=(arr[0]==2 || arr[0]==3);
    for(int q=1;q<n;++q){
        dp[q][0]=max(dp[q-1][0],max(dp[q-1][1],dp[q-1][2]));
        dp[q][1]=max(dp[q-1][0],dp[q-1][2])+(arr[q]%2);
        dp[q][2]=max(dp[q-1][0],dp[q-1][1])+(arr[q]==2 || arr[q]==3);
    }
    cout << n-max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << "\n";
}

