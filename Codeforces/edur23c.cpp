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

ll n,s,res;
ll dgs(ll a){ll ans=0; while(a)ans+=(a%10),a/=10; return ans;}
void solve(){
    ll i,j,mid;
    i=1,j=n;
    while(i<=j){
        mid=(i+j)/2;
        if(mid-dgs(mid)<s) i=mid+1;
        else j=mid-1;
    }
    if(j) res=n-j;
}
int main()
{
    fast_io;
    cin>>n>>s;
    res=0;
    solve();
    cout << res << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



