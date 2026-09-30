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
#define MAX5 100001 //1e5+1
#define MAX9 1000000001 //1e9+1
#define MAX6 1000001 //1e6+1
#define pb(x) push_back(x)

ll t,a,b;
vector<ll> fac(MAX6);
int main()
{
    fast_io;
    auto inv=[](ll x){
        ll ans,m;
        ans=1,m=mdl1-2;
        while(m){
            if(m&1) ans=(ans*x)%mdl1;
            x=(x*x)%mdl1,m/=2;
        }
        return ans;
    };
    fac[0]=1;
    for(int q=1;q<MAX6;++q) fac[q]=q;
    partial_sum(fac.begin(),fac.end(),fac.begin(),[](ll x,ll y){return (x*y)%mdl1;});
    cin>>t;
    while(t--&&cin>>a>>b){
        cout << (((fac[a]*inv(fac[b]))%mdl1)*inv(fac[a-b]))%mdl1 << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



