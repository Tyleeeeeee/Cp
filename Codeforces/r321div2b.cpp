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

int n,d;
int main()
{
    fast_io;
    cin>>n>>d;
    pair<ll,ll> arr[n]; for(auto&v:arr) cin>>v.first>>v.second;
    sort(arr,arr+n);
    ll lp,rp,sum,res;
    for(res=sum=lp=rp=0;rp<n;++rp){
        sum+=arr[rp].second;
        while(arr[rp].first-arr[lp].first>=d){
            sum-=arr[lp++].second;
        }
        res=max(res,sum);
    }
    cout << res << "\n";
}

