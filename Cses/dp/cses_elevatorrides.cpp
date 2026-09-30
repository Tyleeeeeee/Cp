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
#define pb(x) push_back(x)

ll n,x;
pair<ll,ll> dp[1<<20];
int main()
{
    fast_io;
    cin>>n>>x;
    ll a[n]; for(auto&v:a)cin>>v;
    dp[0].first=1,dp[0].second=0;
    for(int q=1;q<(1<<n);++q) dp[q].first=n+1,dp[q].second=0;
    for(ll s=1;s<(1<<n);++s){
        for(int q=0;q<n;++q){
            if(s&(1<<q)){
                auto op=dp[s^(1<<q)];
                if(op.second+a[q]<=x) op.second+=a[q];
                else op.first++,op.second=a[q];
                dp[s]=min(dp[s],op);
            }
        }
    }
    cout << dp[(1<<n)-1].first << "\n";
}
/*
   author :tlx
               */

