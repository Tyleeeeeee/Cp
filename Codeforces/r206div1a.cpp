#include<iostream>
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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,l,r,ql,qr,sum,res;
int main()
{
    fast_io;
    cin>>n>>l>>r>>ql>>qr;
    sum=0,res=1e18;
    vector<ll> arr(n); for(auto&v:arr)cin>>v,sum+=v;
    partial_sum(arr.begin(),arr.end(),arr.begin(),[](ll a,ll b){return a+b;});
    for(int q=0;q<n+1;++q){
        ll x=abs(n-2*q);
        res=min(res,(q>0)*(arr[q-1]*l)+((sum-(q>0?arr[q-1]:0))*r)+(x<=1?0:(x-1)*(n-q>q?qr:ql)));
    } 
    cout << res << "\n";
}
/*
   author :tlx
               */

