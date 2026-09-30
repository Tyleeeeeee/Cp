#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    long long dp[1000][2],N;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1,dp[0][1]=0;
    for(int q=1;q<1000;++q){
        dp[q][0]=dp[q-1][0]*2+dp[q-1][1];
        dp[q][1]=dp[q-1][0]+dp[q-1][1];
    }
    while(cin>>N && N!=-1) cout << dp[N][0] << " " << dp[N][1] << "\n";
}

