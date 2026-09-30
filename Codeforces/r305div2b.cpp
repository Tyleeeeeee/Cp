#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m,qe,i,j,ans,sum,mx;
    cin>>n>>m>>qe;
    int arr[n][m],dp[n];
    for(int q=0;q<n;++q)
        for(int w=0;w<m;++w)
            cin>>arr[q][w];
    sum=mx=0;
    memset(dp,0,sizeof(dp));
    for(int q=0;q<n;++q){ sum=0;
        for(int w=0;w<m;++w){
            sum=arr[q][w]==1?sum+1:0;
            dp[q]=max(dp[q],sum);
        }
    }
    for(int q=0;q<qe;++q){ sum=ans=0;
        cin>>i>>j;
        arr[i-1][j-1]=1-arr[i-1][j-1];
        for(int w=0;w<m;++w){
            sum=arr[i-1][w]==1?sum+1:0;
            ans=max(ans,sum);
        }
        dp[i-1]=ans;
        mx=0;
        for(int w=0;w<n;++w) mx=max(mx,dp[w]);
        cout << mx << "\n";
    }
}

