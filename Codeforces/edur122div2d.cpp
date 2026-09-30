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

ll t,n,k,dp[12001],w[1001],cw[1001];
int main()
{
    fast_io;
    memset(cw,0x3f,sizeof(cw));
    cw[1]=0;
    for(int q=1;q<=1000;++q)
        for(int w=1;w<=q;++w)
            if(q+q/w<=1000) cw[q+q/w]=min(cw[q+q/w],cw[q]+1);
    cin>>t;
    while(t--&&cin>>n>>k){
        for(int q=1;q<=n;++q) cin>>w[q],w[q]=cw[w[q]];
        memset(dp,0,sizeof(dp));
        ll x;
        for(int i=1;i<=n;++i){
            cin>>x;
            for(int j=min(12*n,k);j>=w[i];--j)
                dp[j]=max(dp[j],dp[j-w[i]]+x);
        }
        cout << dp[min(12*n,k)] << "\n";
    }        
}
/*
   author :tlx
               */





