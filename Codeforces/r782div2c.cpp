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

ll t,n,a,b,ans;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>a>>b){
        vector<ll> arr(n+1,0);
        for(int q=1;q<n+1;++q)cin>>arr[q];
        ll sur[n],pref[n],ans;
        sur[n]=pref[0]=0,ans=1e18;
        for(int q=n-1;q>=0;--q) sur[q]=b*(arr[q+1]-arr[q])*(n-q)+sur[q+1];
        for(int q=1;q<n;++q) pref[q]=pref[q-1]+(arr[q]-arr[q-1])*(a+b);
        for(int q=0;q<n;++q) ans=min(ans,pref[q]+sur[q]);
        cout << ans << "\n";
    }
}

