#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    int dp[100][2],n,ans;
    string s;
    while(cin>>s){
        n=s.length();
        memset(dp,0,sizeof(dp));
        int arr[n-1];
        for(int q=0;q<n-1;++q){
            if(s[q]==s[q+1]) arr[q]=-1;
            else arr[q]=(s[q]>s[q+1]);
        } 
        dp[0][0]=(arr[0]==0);
        dp[0][1]=(arr[0]==1);
        for(int q=1;q<n-1;++q){
            if(arr[q]==0){
                dp[q][0]=dp[q-1][1]+1;
                dp[q][1]=dp[q-1][1];
            }
            if(arr[q]==1){
                dp[q][0]=dp[q-1][0];
                dp[q][1]=dp[q-1][0]+1;
            }
            if(arr[q]==-1){
                dp[q][0]=dp[q-1][0];
                dp[q][1]=dp[q-1][1];
            }
        }
        ans=(dp[n-2][0]<dp[n-2][1]?dp[n-2][1]:dp[n-2][0])+1;
        cout << ans << "\n";
    }
}

