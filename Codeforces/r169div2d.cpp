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
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAXXX 100001 //1e5+1
#define MAXX 1000000001 //1e9+1
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll l,r,res;
int main()
{
    fast_io;
    cin>>l>>r;
    res=0;
    ll bit,tmp;
    bit=0,tmp=r;
    while(tmp) bit++,tmp>>=1;
    for(int q=bit-1;~q;--q)
        res+=((((l>>q)&1)^((r>>q)&1))||(!((l>>q)&1)&&(l+(1LL<<q))<=r)||(((l>>q)&1)&&(r-(1LL<<q))>=l))?(1LL<<q):0;
    cout << res << "\n";
}
/*
   author :tlx
               */

