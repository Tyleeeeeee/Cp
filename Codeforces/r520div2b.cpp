#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
const ll mx=1e6;

ll n,res,fix;
int main()
{
    fast_io;
    cin>>n;
    fix=res=0;
    //initial multiple a large number such that reduce number of multiple operation
    while((ll)sqrt(n)==sqrt(n) && n>1) res++,n/=sqrt(n);
    for(ll q=sqrt(n);q>1;--q){
        while(n%(q*q)==0) n/=q,res++,fix=1;
    }
    cout << n << " " << res+fix << "\n";
}

