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

ll n,x[5001],dp[5001][5001];
int main()
{
    fast_io;
    cin>>n;
    vector<ll> pref(n+1,0);
    for(int q=1;q<=n;++q) cin>>x[q],pref[q]=x[q];
    partial_sum(pref.begin(),pref.end(),pref.begin());
    memset(dp,0,sizeof(dp));
    for(int q=n;q;--q){
        for(int w=q;w<=n;++w){
            if(q==w) dp[q][w]=x[q];
            else dp[q][w]=max(x[q]+pref[w]-pref[q]-dp[q+1][w],x[w]+pref[w-1]-pref[q-1]-dp[q][w-1]);
        }
    }
    cout << dp[1][n] << "\n";
}
/*
   author :tlx
               */

