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
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,dp[1415][1415];
int main()
{
    fast_io;
    memset(dp,0,sizeof(dp));
    ll cnt=2;
    dp[1][1]=1;
    for(int q=2;q<=1414;++q){
        for(int w=1;w<=q;++w){
            dp[q][w]+=cnt*cnt-(w>1&&w<q?dp[q-2][w-1]:0)+dp[q-1][w]+dp[q-1][w-1],cnt++;
        }
    }
    cin>>t;
    while(t--&&cin>>n){
        ll x,y;
        x=1;
        while(x*(x+1)/2<n) x++;
        y=n-(x-1)*x/2;
        cout << dp[x][y] << "\n";
    }
}

/*
   author :tlx
               */







