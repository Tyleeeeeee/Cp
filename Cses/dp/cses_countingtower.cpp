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
#define MAX 1000001 //1e6+1

ll t,n,dp[MAX][2];
int main()
{
    fast_io;
    memset(dp,0,sizeof(dp));
    dp[1][0]=dp[1][1]=1;
    for(int q=2;q<MAX;++q){
        dp[q][0]=(2*dp[q-1][0]+dp[q-1][1])%mdl1;
        dp[q][1]=(4*dp[q-1][1]+dp[q-1][0])%mdl1;
    }
    cin>>t;
    while(t--&&cin>>n){
        cout << (dp[n][0]+dp[n][1])%mdl1 << "\n";
    }
}
/*
   author :tlx
               */

