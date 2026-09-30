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

ll n,ub,res;
vector<ll> dp(MAX5);
ll f(ll tar,vector<pair<ll,ll>> &a){
    ll i,j,mid;
    i=0,j=ub-1;
    while(i<=j){
        mid=(i+j)/2;
        if(a[mid].first<tar) i=mid+1;
        else j=mid-1;
    }
    return ub-(j+1)+(j>=0?dp[j]:0);
}
int main()
{
    fast_io;
    cin>>n; 
    vector<pair<ll,ll>> a(n);
    for(int q=0;q<n;++q) cin>>a[q].first>>a[q].second;
    sort(a.begin(),a.end());
    res=min(inf,(dp[0]=0)+n-1);
    for(int q=1;q<n;++q){
        ub=q;
        dp[q]=f(a[q].first-a[q].second,a);
        res=min(res,dp[q]+n-q-1);
    }
    cout << res << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



