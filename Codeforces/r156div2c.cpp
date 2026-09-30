#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<stack>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,res,arr[4001],dp[4001][4001];
int main()
{
    fast_io;
    cin>>n;
    for(int q=1;q<=n;++q) cin>>arr[q];
    res=0;
    memset(dp,0,sizeof(dp));
    for(int q=1;q<=n;++q){
        for(int w=0,k=0;w<q;++w){
            dp[w][q]=dp[k][w]+1;
            res=max(res,dp[w][q]);
            if(w>0 && arr[q]==arr[w]) k=w;
        }
    }
    cout << res << "\n";
}
/*
   author :tlx
               */

