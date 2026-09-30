#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int n,q,l,r,dp[100001];
    string s;
    cin>>n>>q>>s;
    memset(dp,0,sizeof(dp));
    dp[1]=s[0]-'a'+1;
    for(int q=1;q<n;++q){
        dp[q+1]=dp[q]+s[q]-'a'+1;
    }
    while(q-- && cin>>l>>r){
        cout << dp[r]-dp[l-1] << "\n";
    }
}

