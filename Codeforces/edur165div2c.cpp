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

ll t,n,k,a[300001],dp[300001][11];
int main()
{
    fast_io;
    cin>>t;
    memset(dp,0,sizeof(dp));
    while(t--&&cin>>n>>k){
        for(int q=1;q<=n;++q) cin>>a[q];
        for(int q=1;q<=n;++q){
            for(int w=0;w<=k;++w){
                ll mn;
                mn=dp[q][w]=inf;
                for(int i=0;i<=w && ~(q-i-1);i++){
                    mn=min(mn,a[q-i]);
                    dp[q][w]=min(dp[q][w],dp[q-i-1][w-i]+mn*(i+1));
                }
            }
        }
        cout << dp[n][k] << "\n";
    }
}
/*
   author :tlx
               */

