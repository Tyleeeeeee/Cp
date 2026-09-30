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
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int q=1;q<=x;++q){
        for(int w=0;w<n;++w){
            if(q>=c[w]) dp[q]=(dp[q]+dp[q-c[w]])%mdl;
        }
    }
    cout << dp[x] << "\n";
}
/*
   author :tlx
               */



