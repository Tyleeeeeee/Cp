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

const ll mdl=1e9+7;
ll dp[200001],t,n;
ll solve(ll dn)
{
    if(dn==1) return 1;
    dn%=mdl;
    ll a,b,c,d,e;
    a=mdl,b=dn,d=0,e=1;
    while(b){
        c=a/b;
        ll tmp=d;
        d=e,e=tmp-c*e;
        a%=b,swap(a,b);
    }
    d=(d%mdl+mdl)%mdl;
    return d;
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll arr[n],sum,dn;
        for(auto&v:arr)cin>>v;
        memset(dp,0,sizeof(dp));
        dp[n-1]=arr[n-1];
        for(int q=n-2;q;--q) dp[q]=(arr[q]+dp[q+1])%mdl;
        sum=0;
        for(int q=0;q+1<n;++q){
            sum+=(arr[q]*dp[q+1])%mdl;
        }
        dn=n*(n-1)/2;
        cout << ((sum%mdl)*(solve(dn)%mdl))%mdl << "\n";
    }
}

