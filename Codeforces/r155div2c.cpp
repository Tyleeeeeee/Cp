#include<iostream>
#include<string>
#include<cstring>
using namespace std;

#define modl (998244353)
int dp[200001];

long long fact(long long N)
{
    if(N==1 || N==0)return 1;
    return (N*fact(N-1))%modl;
}
int main()
{
    int t,n;
    long long mip,ans,rpt;
    string s;
    cin>>t;
    while(t--&&cin>>s){ n=s.length(); rpt=ans=0,mip=1;
        memset(dp,0,sizeof(dp));
        dp[1]=-1;
        for(int q=1;q<n;++q){
            dp[q+1]=(s[q]!=s[q-1]?q:dp[q]);
        }
        for(int q=2;q<=n;++q){
            if(dp[q]==dp[q-1]) rpt++;
            else if(rpt) ans+=rpt,mip*=rpt+1,mip%=modl,rpt=0;
        }
        if(rpt) ans+=rpt,mip*=rpt+1,mip%=modl;
        mip*=fact(ans),mip%=modl;
        cout << ans << " " << mip << "\n";
    }
}

