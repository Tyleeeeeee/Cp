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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
const ll mdl=1e9+7;

ll k,res;
vector<ll> fac(1001,1);
int main()
{
    fast_io;
    auto inv=[](ll a){
        ll m=mdl-2,ans=1;
        while(m){if(m&1)ans=(ans*a)%mdl; a=(a*a)%mdl,m/=2;}
        return ans;
    };
    for(ll q=2;q<1001;++q) fac[q]=q;
    partial_sum(fac.begin(),fac.end(),fac.begin(),[](ll a,ll b){return (a*b)%mdl;});
    cin>>k;
    ll arr[k],sum;
    for(int q=0;q<k;++q)cin>>arr[q];
    res=1,sum=0;
    for(int q=0;q<k;++q){
        // (sum+arr[q]-1)C(arr[q]-1)
        res=(res*((fac[sum+arr[q]-1]*inv(fac[sum])%mdl)*inv(fac[arr[q]-1])%mdl))%mdl;
        sum+=arr[q];
    }
    cout << (res%mdl) << "\n";
}
/*
   author :tlx
               */

