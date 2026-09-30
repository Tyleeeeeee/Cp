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
#define MAXX 1000000001 //1e9+1
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll t,x,dp[MAX];
int main()
{
    fast_io;
    memset(dp,0,sizeof(dp));
    for(int q=1;q<MAX;++q)
        for(int w=q;w<MAX;w+=q) dp[w]++;
    cin>>t;
    while(t--&&cin>>x) cout << dp[x] << "\n";
}
/*
   author :tlx
               */

