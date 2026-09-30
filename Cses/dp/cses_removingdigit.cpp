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

ll n,dp[MAX];
int main()
{
    fast_io;
    auto ld=[](ll a){
        ll ans=0;
        while(a)ans=max(ans,a%10),a/=10;
        return ans;
    };
    memset(dp,0,sizeof(dp));
    for(int q=1;q<MAX;++q) dp[q]=1+dp[q-ld(q)];
    cin>>n;
    cout << dp[n] << "\n";
}
/*
   author :tlx
               */



