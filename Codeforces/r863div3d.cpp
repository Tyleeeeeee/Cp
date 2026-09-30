#include<iostream>
#include<bitset>
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
#include<unordered_map>
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
#define is(x) insert(x)
#define log2(x) (log(x)/log(2))

ll t,n,x,y;
ll dfs(ll wi,ll hi,ll X,ll Y){
    if(wi==1) return 1;
    if(Y>=hi-wi+1 && Y<=wi) return 0;
    return dfs(hi-wi,wi,min(abs(Y-hi)+1,Y),X);
}
int main()
{
    fast_io;
    ll dp[50];
    dp[0]=dp[1]=1;
    for(int q=2;q<=45;++q) dp[q]=dp[q-1]+dp[q-2];
    cin>>t;
    while(t--&&cin>>n>>x>>y){
        cout << (dfs(dp[n],dp[n+1],x,y)?"YES":"NO") << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







