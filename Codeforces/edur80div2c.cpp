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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,m,dp[11][1001],res;
int main()
{
    fast_io;
    cin>>n>>m;
    res=0;
    memset(dp,0,sizeof(dp));
    for(int w=1;w<=n;++w) dp[0][w]=1;
    for(int q=1;q<=m-1;++q) for(int w=1;w<=n;++w) dp[q][w]=(w==1?1:dp[q][w-1]%mdl+dp[q-1][w]%mdl)%mdl;
    for(int q=n;q;--q){
        for(int w=q;w;--w){
            //pref[q]->bn=q surf[w]->an=w
            res=(res+dp[m-1][w]*dp[m-1][n+1-q])%mdl;
        }
    }
    cout << res%mdl << "\n";
}
/*
   author :tlx
               */



