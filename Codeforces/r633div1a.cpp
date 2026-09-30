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
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,res;
int main()
{
    fast_io;
    auto clz=[](ll m)->ll{
       ll bit;
       bit=0;
       while(m)bit++,m>>=1;
       return bit;
    };
    cin>>t;
    while(t--&&cin>>n){
        ll tmp,bp;
        res=0,bp=-1e18;
        while(n--&&cin>>tmp) res=max(res,clz(max(bp,tmp)-tmp)),bp=max(bp,tmp);
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

