#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int t,ans,dp[26];
    string s;
    cin>>t;
    while(t--&&cin>>s){ ans=0; memset(dp,0,sizeof(dp));
        for(int q=0;q<s.length();++q){
            if(!dp[s[q]-'a']) dp[s[q]-'a']++;
            else {ans+=2,memset(dp,0,sizeof(dp));}
        }
        cout << s.length()-ans << "\n";
    }
}


