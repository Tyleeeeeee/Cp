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

ll n,ub,dp[MAX5];
vector<ll> t(MAX5);
ll f(ll a,ll ti,ll rb){
    auto it=upper_bound(t.begin(),t.begin()+ub,a-ti);
    return rb+(it==t.begin()?0:dp[it-t.begin()-1]);
}
int main()
{
    fast_io;
    cin>>n;
    for(int q=0;q<n;++q){
        cin>>t[q],ub=q;
        dp[q]=(!q?20:min(f(t[q],1440,120),min(f(t[q],90,50),20+dp[q-1])));
    }
    ll sum=0;
    for(int q=0;q<n;++q){
        cout << (dp[q]-sum>0?dp[q]-sum:0) << "\n";
        sum+=dp[q]-sum;
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



