#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    int t,n,p,k,x,y,ans,mv,dp[100000];
    string s;
    cin>>t;
    while(t--&&cin>>n>>p>>k>>s>>x>>y){
        ans=1e8;
        memset(dp,0,sizeof(dp));
        for(int q=n-1;q>=n-k;--q) dp[q]=1-s[q]+'0';
        for(int q=n-k-1;q>=p-1;--q) dp[q]=dp[q+k]+(1-s[q]+'0');
        for(int q=p-1;q<n;++q){
            ans=ans>y*(q-p+1)+x*dp[q]?y*(q-p+1)+x*dp[q]:ans;
        }
        cout << ans << "\n";
    }
}

