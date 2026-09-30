#include<iostream>
#include<fstream>
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
#include<set>
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX 1000001 //1e6+1

ll n,m,res,dp[100000][102];
int main()
{
    fast_io;
    cin>>n>>m;
    ll x[n]; for(auto&v:x)cin>>v;
    res=0;
    memset(dp,0,sizeof(dp));
    if(x[0]) dp[0][x[0]]=1;
    else for(int q=1;q<=m;++q) dp[0][q]=1;
    for(int q=1;q<n;++q){
        if(x[q]) dp[q][x[q]]=(dp[q-1][x[q]]+dp[q-1][x[q]-1]+dp[q-1][x[q]+1])%mdl;
        else{
            for(int w=1;w<=m;++w) dp[q][w]=(dp[q-1][w]+dp[q-1][w-1]+dp[q-1][w+1])%mdl;
        }
    }
    for(int q=1;q<=m;++q) res=(res+dp[n-1][q])%mdl;
    cout << res << "\n";
}
/*
   author :tlx
               */



