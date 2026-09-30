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
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,res,a[200000];
ll gcd(ll a,ll b){if(!b) return a; while(a%=b)swap(a,b); return b;}
void solve(ll l){
    ll ans=0;
    for(int q=l;q<n;++q){
        ans=gcd(ans,abs(a[q]-a[q-l]));
        if(ans==1) return;
    }
    res++;
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        for(int q=0;q<n;++q) cin>>a[q];
        res=1;
        for(int l=1;l<n;++l) if(!(n%l)) solve(l);
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

