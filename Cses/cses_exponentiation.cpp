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

ll t,n,k;
void solve(){
    ll ans=1;
    while(n){
        if(n&1) ans=(ans*k)%mdl1;
        k=(k*k)%mdl1,n/=2;
    }
    cout << ans << "\n";
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>k>>n){
        solve();
    }
}
/*
   author :tlx
               */

