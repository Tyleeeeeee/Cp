#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

using ll=long long ;
int dp[200000][2];
int main()
{
    ll t,n,ans;
    string s;
    cin>>t;
    while(t--&&cin>>s){ ans=0;
        n=s.length();
        memset(dp,0,sizeof(dp));
        dp[0][0]=(s[0]=='0'||s[0]=='?');
        dp[0][1]=(s[0]=='1'||s[0]=='?');
        for(int q=1;q<n;++q){
            //Its is a different between subsequence and substring
            //There is two type of dp array
            //1)if(arr[q]==0){
            //      dp[q][0]=max/min(dp[q-1][0],dp[q-1][1])+1
            //      dp[q][1]=dp[q-1][1]
            //      this step is same as you throw the character or whatever else of q,so this is a subsequence
            //      algorithm
            //}
            //2)if(arr[q]==0){
            //      dp[q][0]=max/min(dp[q-1][0],dp[q-1][1])+1
            //      dp[q][1]=0
            //      If it is a substring of subarray(which mean consecutive) you cannnot just inherit dp[q][1] from 
            //      previous dp[q-1][1] because inherit is same as the action which you throw the q-th character or
            //      whatever else,the right way is you need to set it to 0,this mean if you want to make q-th data
            //      become 1 it is impossible if it is consecutive
            //}
            dp[q][0]=(1-(s[q]=='1'))*(dp[q-1][1]+1);
            dp[q][1]=(1-(s[q]=='0'))*(dp[q-1][0]+1);
        }
        for(int q=0;q<n;++q) ans+=max(dp[q][0],dp[q][1]);
        cout << ans << "\n";
    }
}

