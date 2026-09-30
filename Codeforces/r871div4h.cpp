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

ll t,n,k,res,a[200001];
int main()
{
    fast_io;
    auto cst=[](ll a){
        ll ans=0;
        while(a) ans+=(a&1),a>>=1;
        return ans;
    };
    cin>>t;
    while(t--&&cin>>n>>k){
        for(int q=1;q<=n;++q) cin>>a[q];
        res=0;
        vector<vector<ll>> dp(n+1,vector<ll>(1<<6,0));
        for(int q=1;q<=n;++q){
            for(int w=0;w<(1<<6);++w) dp[q][w]=(dp[q][w]+dp[q-1][w])%mdl1,dp[q][w&a[q]]=(dp[q][w&a[q]]+dp[q-1][w])%mdl1;
            dp[q][a[q]]=(dp[q][a[q]]+1)%mdl1;
        }
        for(int q=0;q<(1<<6);++q) res=(res+(cst(q)==k?dp[n][q]:0))%mdl1;
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

