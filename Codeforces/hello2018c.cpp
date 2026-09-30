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

ll n,L,res;
int main()
{
    fast_io;
    cin>>n>>L;
    ll c[n]; 
    res=inf;
    for(int q=0;q<n;++q) cin>>c[q],c[q]=(q?min(2*c[q-1],c[q]):c[q]);
    ll sum;
    sum=0;
    for(int q=n-1;q>=0;--q){
        ll x=(L/(1<<q));
        sum+=x*c[q];
        L-=(x*(1<<q));
        res=min(res,sum+(L>0)*c[q]);
    }
    cout << res << "\n";
}
/*
   author :tlx
               */

