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

ll t,a,b,c;
ll solve(ll k,ll n,ll mdl){
    ll ans=1;
    while(n){
        if(n&1) ans=(ans*k)%mdl;
        k=(k*k)%mdl,n/=2;
    }
    return ans;
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>a>>b>>c){
        cout << solve(a,solve(b,c,mdl1-1),mdl1) << "\n";
    }
}
/*
   author :tlx
               */

