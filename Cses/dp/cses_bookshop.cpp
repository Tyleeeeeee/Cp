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

ll n,x,dp[100001];
int main()
{
    fast_io;
    cin>>n>>x;
    ll h[n],s[n]; for(auto&v:h)cin>>v; for(auto&v:s)cin>>v;
    memset(dp,0,sizeof(dp));
    for(int q=0;q<n;++q){
        for(int w=x;w>=h[q];--w){
            dp[w]=max(dp[w],dp[w-h[q]]+s[q]);
        }
    }
    cout << dp[x] << "\n";
}
/*
   author :tlx
               */



