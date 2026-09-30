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

ll n,x,dp[MAX];
int main()
{
    fast_io;
    cin>>n>>x;
    ll c[n]; for(auto&v:c)cin>>v;
    memset(dp,0x7F,sizeof(dp));
    dp[0]=0;
    for(int q=0;q<n;++q){
        for(int w=c[q];w<=x;++w) dp[w]=min(dp[w],1+dp[w-c[q]]);
    }
    cout << (dp[x]!=0x7F7F7F7F7F7F7F7F?dp[x]:-1) << "\n";
}
/*
   author :tlx
               */



