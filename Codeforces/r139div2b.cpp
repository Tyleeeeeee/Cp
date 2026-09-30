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

ll s,k,dp[100];
ll solve(ll tar,ll up){
    ll i,j,mid;
    i=0,j=up-1;
    while(i<=j){
        mid=(i+j)/2;
        if(dp[mid]<=tar) i=mid+1;
        else j=mid-1;
    }
    return dp[j];
}
int main()
{
    fast_io;
    cin>>s>>k;
    vector<ll> ans;
    memset(dp,0,sizeof(dp));
    ll i;
    dp[0]=1;
    for(i=0;;++i){
        for(int q=i-1;q>=max(i-k,0LL);--q) dp[i]+=dp[q];
        if(dp[i]>=1e9) break;
    }
    while(s){
        ll x=solve(s,i);
        ans.push_back(x),s-=x;
    }
    ans.push_back(0);
    cout << ans.size() << "\n";
    for(auto v:ans) cout << v << " ";
    cout << "\n";
}
/*
   author :tlx
               */



