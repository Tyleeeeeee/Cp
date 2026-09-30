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


ll t,n,h,arr[200000];
ll solve(ll i,ll pwr,ll g,ll b)
{
    ll ans1,ans2;
    if(i==n) return 0;
    if(pwr>arr[i]) return solve(i+1,pwr+arr[i]/2,g,b)+1;
    else{
        ans1=g>0?solve(i,pwr*2,g-1,b):0;
        ans2=b>0?solve(i,pwr*3,g,b-1):0;
    }
    return max(ans1,ans2);
}
int main()
{
    //backtraking and dfs & similar
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>h){
        for(int q=0;q<n;++q)cin>>arr[q];
        sort(arr,arr+n);
        cout << solve(0,h,2,1) << "\n";
    }
}

