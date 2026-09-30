#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int t,n;
    string s[2];
    cin>>t;
    while(t--&&cin>>n>>s[0]>>s[1]){ int dp[2][n];
        memset(dp,0,sizeof(dp));
        dp[0][0]=dp[1][1]=1;
        for(int q=2;q<n;++q){
            dp[0][q]=(s[0][q-1]=='>' && (dp[0][q-2]||dp[1][q-1]));
            dp[1][q]=(s[1][q-1]=='>' && (dp[1][q-2]||dp[0][q-1]));
        }
        cout << (dp[1][n-1]?"YES":"NO") << "\n";
    }
}


