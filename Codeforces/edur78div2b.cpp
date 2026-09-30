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
const ll mx=1e18;

ll t,a,b,res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>a>>b){
        ll ok;
        ok=res=0;
        if(a!=b){
            for(ll q=max(a,b);q<=mx && !ok;++q){
                ll x=sqrt(2*(2*q-a-b));
                if(x*(x+1)==(2*(2*q-a-b))) res=x,ok=1;
            }
        }
        cout << res << "\n";
    }
}

