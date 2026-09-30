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

ll n,p,res;
int main()
{
    fast_io;
    auto solve=[](ll a){
        ll ans=0;
        while(a)ans+=(a&1),a>>=1;
        return ans;
    };
    cin>>n>>p;
    ll i;
    //n-kp;
    for(i=1;i<=32;++i){
        n-=p;
        if(n>=i && solve(n)<=i) break;
    }
    cout << (i<33?i:-1) << "\n";
}
/*
   author :tlx
               */

