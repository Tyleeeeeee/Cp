#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
    int t,n,ans,dp[200001];
    string s;
    cin>>t;
    while(t--&&cin>>n>>s){
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int q=2;q<=s.length();++q){
            dp[q]=(s[q-1]==s[q-2]?dp[q-1]:q);
        }
        for(int x=2;x<=n;++x){
            if(x>2) cout << " ";
            cout << dp[x-1];
        }
        cout << "\n";
    }
}

