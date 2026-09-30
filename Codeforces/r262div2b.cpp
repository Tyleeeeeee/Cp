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
const ll mx=1e9;

ll a,b,c;
ll solve(ll q){
    ll n=a,m=q,ans=b;
    while(n){if(n&1)ans*=m; m*=m,n>>=1;}
    ans+=c;
    ll x=ans,dgs=0;
    while(x) dgs+=x%10,x/=10;
    return (dgs==q && ans<mx?ans:-1);
}
int main()
{
    fast_io;
    cin>>a>>b>>c;
    vector<ll> ans;
    for(ll q=1;q<=81;++q){
        ll x=solve(q);
        if(x!=-1) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    if(ans.size()){for(auto v:ans)cout << v << " "; cout << "\n";} 
}
/*
   author :tlx
               */

