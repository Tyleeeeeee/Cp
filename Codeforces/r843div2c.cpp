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

ll t,n,x,res;
int main()
{
    fast_io;
    auto lsb=[](ll a){
        return (a & -a);
    };
    cin>>t;
    while(t--&&cin>>n>>x){
        ll m;
        m=n;
        while(m>x){
            n+=lsb(n);
            m=(m&n);
        }
        res=(m==x?n:-1);
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

