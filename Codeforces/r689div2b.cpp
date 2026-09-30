#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char c;
int arr[500][500],dp[500][500],t,n,m,ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--&&cin>>n>>m){ ans=0;
        for(int q=0;q<n;++q)
            for(int w=0;w<m;++w)cin>>c,arr[q][w]=c=='.'?0:1;
        memset(dp,0,sizeof(dp));
        for(int q=0;q<m;++q) dp[n-1][q]+=arr[n-1][q];
        for(int q=n-2;q>=0;--q){
            for(int w=0;w<m;++w){
                //no need loop through 1 to k row check arr[q+1][w-1] && arr[q+1][w+1] is enough 
                //ans is min(arr[q+1][w-1],arr[q+1][w+1])!
                dp[q][w]+=arr[q][w]+(arr[q][w])*(w>0 && w<m-1 && dp[q+1][w] ? min(dp[q+1][w-1],dp[q+1][w+1]) : 0);
                ans+=dp[q][w];
            }
        }
        for(int q=0;q<m;++q) ans+=dp[n-1][q];
        cout << ans << "\n";
    }
}

