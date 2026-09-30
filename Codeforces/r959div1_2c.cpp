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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,x,dp[200002],res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>x){
        vector<ll> a(n+1); for(int q=1;q<=n;++q) cin>>a[q];
        partial_sum(a.begin()+1,a.end(),a.begin()+1,[](ll a,ll b){return a+b;});
        memset(dp,0,sizeof(dp));
        res=dp[n]=0;
        for(int q=n-1;q>=0;--q){
            ll dif=upper_bound(a.begin()+1,a.end(),a[q]+x)-a.begin();
            dp[q]=dif-q-1+dp[dif];
            res+=dp[q];
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */





