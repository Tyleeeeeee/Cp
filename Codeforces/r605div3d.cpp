#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,arr[200000],dp[200000],res;
int main()
{
    fast_io;
    cin>>n;
    for(int q=0;q<n;++q) cin>>arr[q];
    vector<ll> pref(n,1),surf(n,1);
    for(int q=0;q<n;++q){
        if(q>0) pref[q]=(arr[q]>arr[q-1]?pref[q-1]+1:1),surf[n-q-1]=(arr[n-q-1]<arr[n-q]?surf[n-q]+1:1);
    }
    res=0,dp[0]=(surf[1]==1?0:surf[1]),dp[n-1]=(pref[n-2]==1?0:pref[n-2]);
    for(int q=1;q+1<n;++q){
        if(arr[q-1]<arr[q+1]) dp[q]=pref[q-1]+surf[q+1];
        else dp[q]=(max(pref[q-1],surf[q+1])==1?0:max(pref[q-1],surf[q+1]));
    }
    res=max(res,pref[n-1]);
    for(int q=0;q<n;++q) res=max(res,dp[q]);
    cout << res << "\n";
}

