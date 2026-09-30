#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
using ll=long long;

ll dp[100001][2],arr[100001],n,ans;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);

    cin>>n;
    memset(arr,0,sizeof(arr)),memset(dp,0,sizeof(dp));
    ll tmp,mx;
    ans=mx=0;
    for(int q=0;q<n;++q)cin>>tmp,arr[tmp]+=tmp,mx=max(mx,tmp);
    dp[mx][1]=arr[mx];
    for(int q=mx-1;q>=0;--q){
        dp[q][0]=max(dp[q+1][0],dp[q+1][1]);
        dp[q][1]=arr[q]+dp[q+1][0];
    }
    cout << max(dp[0][0],dp[0][1]) << "\n";
}

