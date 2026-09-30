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

ll a,b,dp[501][501];
int main()
{
    fast_io;
    cin>>a>>b;
    memset(dp,0x7F,sizeof(dp));
    for(int q=1;q<=a;++q){
        for(int w=1;w<=b;++w){
            if(q==w) dp[q][w]=0;
            else{
                for(int k=1;k<q;++k) dp[q][w]=min(dp[q][w],dp[q-k][w]+dp[k][w]+1);
                for(int k=1;k<w;++k) dp[q][w]=min(dp[q][w],dp[q][w-k]+dp[q][k]+1);
            }
        }
    }
    cout << dp[a][b] << "\n";
}
/*
   author :tlx
               */

