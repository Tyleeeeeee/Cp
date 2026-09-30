#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,arr[2001],dp[2001][2001],res;
int main()
{
    fast_io;
    cin>>n;
    for(int q=1;q<=n;++q)cin>>arr[q];
    for(int q=0;q<2001;++q) 
        for(int w=0;w<2001;++w)
            dp[q][w]=-1e18;
    dp[0][0]=0;
    for(int q=1;q<=n;++q){
        for(int w=0;w<=q;++w){
            if(!w) dp[q][w]=0;
            else if(dp[q-1][w-1]<0) dp[q][w]=dp[q-1][w];
            else dp[q][w]=max(dp[q-1][w-1]+arr[q],dp[q-1][w]);
        }
    }
    res=0;
    for(ll q=1;q<=n;++q) if(dp[n][q]>=0) res=max(res,q);
    cout << res << "\n";
}

