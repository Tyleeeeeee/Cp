#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,arr[500000],dp[6],min,ans;
    cin>>n;
    min=0x16161616;
    memset(dp,0,sizeof(dp));
    for(int q=0;q<n;++q)cin>>arr[q];
    for(int q=0;q<n;++q){
        int i;
        i=(arr[q]==4?0:arr[q]==8?1:arr[q]==15?2:arr[q]==16?3:arr[q]==23?4:5);
        if(!i) dp[i]++;
        else if(dp[i-1]>dp[i]) dp[i]++;
    }
    for(int q=0;q<6;++q)min=min<dp[q]?min:dp[q];
    if(!min) ans=n;
    else ans=n-min*6;
    cout << ans << "\n";
}

