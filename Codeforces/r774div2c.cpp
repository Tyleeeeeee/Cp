#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

const ll mx=1e12;
ll n,t,ans1,ans2;
vector<ll> dp;
ll solve(ll n)
{
    ll ans2,k;
    ans2=1e18,k=dp.size();
    for(int mask=0;mask<(1<<k);++mask){
        ll sum=0,l=0;
        for(int i=0;i<k;++i){
            if(mask & (1<<i)){
                sum+=dp[i],l++;
            }
        }
        if(sum>n) continue;
        ll res=n-sum;
        while(res) l+=(res&1),res>>=1;
        ans2=min(ans2,l);
    }
    return ans2;
}
int main()
{
    fast_io;
    dp.push_back(6);
    for(int q=4;q<16;++q) dp.push_back(dp[dp.size()-1]*q);
    cin>>t;
    while(t--&&cin>>n){
        cout << solve(n) << "\n";
    }
}

