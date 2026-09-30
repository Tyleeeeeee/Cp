#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    string s;
    int dp[100000][2];
    memset(dp,0,sizeof(dp));
    cin>>s;
    dp[0][0]=isupper(s[0])?0:1;
    dp[0][1]=islower(s[0])?0:1;
    for(int q=1;q<s.length();++q){
        dp[q][0]=dp[q-1][0]+(isupper(s[q])?0:1);
        dp[q][1]=min(dp[q-1][0],dp[q-1][1])+(islower(s[q])?0:1);
    }
    cout << min(dp[s.length()-1][0],dp[s.length()-1][1]) << "\n";
}

