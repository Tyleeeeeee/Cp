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
#define pb(x) push_back(x)

ll n,dp[200001],res;
vector<pair<ll,pair<ll,ll>>> a(200001);
ll solve(ll tar){
    ll i,j,mid;
    i=1,j=n;
    while(i<=j){
        mid=(i+j)/2;
        if(a[mid].first<tar) i=mid+1;
        else j=mid-1;
    }
    return j;
}
int main()
{
    fast_io;
    cin>>n;
    for(int q=1;q<=n;++q) cin>>a[q].second.first>>a[q].first>>a[q].second.second;
    res=0;
    sort(a.begin()+1,a.begin()+n+1);
    memset(dp,0,sizeof(dp));
    for(int q=1;q<=n;++q){
        dp[q]=max(dp[q-1],a[q].second.second+dp[solve(a[q].second.first)]);
        res=max(res,dp[q]);
    }
    cout << res << "\n";
}
/*
   author :tlx
               */

