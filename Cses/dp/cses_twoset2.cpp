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
#define MAX 1000001 //1e6+1

ll n,dp[125251],res;
int main()
{
    fast_io;
    auto inv=[](ll a){
        ll m=mdl1-2,ans=1;
        while(m){
            if(m&1) ans=(ans*a)%mdl1;
            a=(a*a)%mdl1,m/=2;
        }
        return ans;
    };
    cin>>n;
    ll x=n*(n+1)/2;
    if(x&1){res=0; goto end;}
    else x/=2;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int q=1;q<=n;++q){
        for(int w=x;w>=q;--w) dp[w]=(dp[w]+dp[w-q])%mdl1;
    }
    res=(dp[x]*inv(2))%mdl1;
    end:
    cout << res << "\n";
}
/*
   author :tlx
               */

