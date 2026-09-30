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
#include<set>
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,ok,one,two;
map<ll,ll> mp;
int main()
{
    fast_io;
    cin>>n;
    string ans(n,'A');
    one=two=0;
    ll arr[n]; for(auto&v:arr)cin>>v,mp[v]++;
    for(auto x:mp){
        if(x.second==1) one++;
        else if(x.second>2) two=x.first;
    }
    ok=1;
    if(one&1 && !two) ok=0;
    else{
        ll a,b;
        if(one&1) for(int q=0;q<n;++q) if(arr[q]==two) {ans[q]='B'; break;}
        a=0,b=(one&1)?1:0;
        for(int q=0;q<n;++q){
            if(mp[arr[q]]==1){
                if(a>b) ans[q]='B',b++;
                else ans[q]='A',a++;
            }
        }
    }
    cout << (ok?"YES":"NO") << "\n";
    if(ok) cout << ans << "\n";
}
/*
   author :tlx
               */



