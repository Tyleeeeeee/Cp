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

ll n,res;
int main()
{
    fast_io;
    ll sum,tmp,mx;
    cin>>n;
    mx=sum=0;
    for(int q=0;q<n;++q) cin>>tmp,sum+=tmp,mx=max(mx,tmp);
    cout << max((ll)ceil((double)sum/(n-1)),mx) << "\n";
}
/*
   author :tlx
               */

