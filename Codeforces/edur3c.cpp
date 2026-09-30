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

ll n,res;
int main()
{
    fast_io;
    cin>>n;
    ll arr[n],sum=0; for(auto&v:arr)cin>>v,sum+=v;
    sort(arr,arr+n);
    ll a,b,acnt;
    a=sum/n,b=a+1,acnt=(n-sum%n),res=0;
    for(ll x:arr){
        if(x>a) continue;
        if(acnt) res+=a-x,acnt--;
        else res+=b-x;
    }
    cout << res << "\n";
}
/*
   author :tlx
               */

