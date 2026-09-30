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

ll n,res,tmp,mx;
vector<ll> x(MAX,0);
int main()
{
    fast_io;
    cin>>n;
    mx=0;
    for(ll q=0;q<n;++q)cin>>tmp,x[tmp]++,mx=max(mx,tmp);
    res=1;
    for(ll q=mx;q;--q){
        ll sum=0;
        for(int w=q;w<=mx;w+=q) sum+=x[w];
        if(sum>1) res=max(res,q);
    }
    cout << res << "\n";
}
/*
   author :tlx
               */

