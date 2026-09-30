#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int solve(int l)
{
    int ans=0;
    while(l){l/=3,ans++;}
    return ans;
}
int main()
{
    int t,l,r,dp[200001],ans;
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    for(int q=2;q<200001;++q){
        dp[q]=dp[q-1]+solve(q);
    }
    cin>>t;
    while(t--&&cin>>l>>r){ ans=2*solve(l)+dp[r]-dp[l];
        cout << ans << "\n";
    }
}

