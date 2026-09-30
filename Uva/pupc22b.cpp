#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int t,dp[1001][1001];
    string s;
    cin >> t;
    cin.get();
    while(t-- && cin>>s)
    {
       memset(dp,0,sizeof(dp));
       for(int l=2;l<=s.length();++l)
       {
           for(int q=1;q+l-1<=s.length();++q)
           {
              int w=q+l-1;
              if(s[q-1]==s[w-1])
              {
                    if(q!=w-1) dp[q][w]=dp[q+1][w-1];
                    else dp[q][w]=0;
              }
              else{
                    if(q!=w-1) dp[q][w]=min(min(dp[q+1][w]+1,dp[q][w-1]+1),dp[q+1][w-1]+1);
                    else dp[q][w]=1;
              }
           }
       }
       cout << dp[1][s.length()] << "\n";
    }
}

