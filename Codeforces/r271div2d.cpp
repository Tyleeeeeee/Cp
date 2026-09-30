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

ll t,k,a,b;
vector<ll> dp(MAXXX),ans(MAXXX);
int main()
{
    fast_io;
    cin>>t>>k;
    dp[0]=1;
    for(int q=1;q<MAXXX;++q){
        if(q<k) dp[q]=1;
        else dp[q]=(dp[q-1]+dp[q-k])%mdl1;
    }
    partial_sum(dp.begin(),dp.end(),ans.begin());
    while(t--&&cin>>a>>b){
        cout << (ans[b]-ans[a-1])%mdl1 << "\n";
    }
}
/*
   author :tlx
               */



