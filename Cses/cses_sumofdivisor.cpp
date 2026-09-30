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
#define MAXX 1000000001 //1e9+1
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll n,res;
ll sum(ll s){
    if(!s) return 0;
    return ((((s%mdl1)*((s+1)%mdl1))%mdl1)*(((mdl1+1)/2)%mdl1))%mdl1;
}
int main()
{
    fast_io;
    cin>>n;
    res=0;
    for(ll q=1;q<=n;++q){
        ll w=n/(n/q);
        res=(res%mdl1+((n/q)%mdl1)*(sum(w)-sum(q-1)+mdl1)%mdl1)%mdl1,q=w;
    }
    cout << res%mdl1 << "\n";
}
/*
   author :tlx
               */

