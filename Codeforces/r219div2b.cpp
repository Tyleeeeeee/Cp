#include<iostream>
#include<fstream>
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
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll w,m,k,res;
ll S(ll n){
    ll ans=0;
    while(n) ans++,n/=10;
    return ans;
}
void solve(){
    ll i,j,mid;
    i=0,j=1e16;
    while(i<=j){
        mid=(i+j)/2;
        ll a,b,ok;
        ull cost;
        ok=1,cost=0,a=mid,b=m;
        while(a && ok){
            ll x=pow(10,S(b))-b;
            ok=(cost>w?0:1);
            if(x>=a) cost+=S(b)*k*a,a-=a;
            else cost+=S(b)*k*x,a-=x,b=pow(10,S(b));
        }
        if(cost<=w) res=max(res,mid),i=mid+1;
        else j=mid-1;
    }
}
int main()
{
    fast_io;
    cin>>w>>m>>k;
    res=0;
    solve();
    cout << res << "\n";
}
/*
   author :tlx
               */



