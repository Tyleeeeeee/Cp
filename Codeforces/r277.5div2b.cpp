#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    int dp[2][101],n,m,ans=0;
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int q=0;q<n;++q)cin>>dp[0][q];
    cin>>m;
    for(int q=0;q<m;++q)cin>>dp[1][q];
    sort(dp[0],dp[0]+n);
    sort(dp[1],dp[1]+m);
    int i=0,j=n>m?n-1:m-1,k=n>m?1:0,l=n>m?0:1;
    for(int q=0;q<min(n,m);)
    {
        if(i<=j && abs(dp[k][q]-dp[l][i])<=1){q++,i++,ans++;}
        else if(dp[k][q]-dp[l][i] > 0) i++;
        else q++;
    }
    cout << ans << "\n";
}

