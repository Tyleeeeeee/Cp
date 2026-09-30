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
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAXXX 100001 //1e5+1
#define MAXX 1000000001 //1e9+1
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll n,k,res,dp[1002][2001][1<<2];
int main()
{
    fast_io;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[1][1][0]=dp[1][1][3]=dp[1][2][1]=dp[1][2][2]=1;
    for(int q=2;q<=n;++q){
        for(int w=1;w<=2*q;++w){
            dp[q][w][0]=(dp[q-1][w][0]+dp[q-1][w][1]+dp[q-1][w][2]+dp[q-1][w-1][3])%mdl2;
            dp[q][w][1]=(dp[q-1][w-1][0]+dp[q-1][w][1]+dp[q-1][w-2][2]+dp[q-1][w-1][3])%mdl2;
            dp[q][w][2]=(dp[q-1][w-1][0]+dp[q-1][w-2][1]+dp[q-1][w][2]+dp[q-1][w-1][3])%mdl2;
            dp[q][w][3]=(dp[q-1][w-1][0]+dp[q-1][w][1]+dp[q-1][w][2]+dp[q-1][w][3])%mdl2;
        }
    }
    cout << (dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mdl2 << "\n";
}
/*
   author :tlx
               */



