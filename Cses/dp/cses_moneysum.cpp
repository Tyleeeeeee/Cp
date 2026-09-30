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

ll n,x[101],dp[100001],res;
int main()
{
    fast_io;
    cin>>n;
    for(int q=1;q<=n;++q)cin>>x[q];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int q=1;q<=n;++q){
        for(int w=100000;w>=x[q];--w) dp[w]=dp[w]+dp[w-x[q]];
    }
    res=0;
    for(int q=1;q<=100000;++q) if(dp[q]) res++;
    cout << res << "\n";
    for(int q=1;q<=100000;++q) if(dp[q]) cout << q << " ";
    if(res) cout << "\n";
}
/*
   author :tlx
               */

