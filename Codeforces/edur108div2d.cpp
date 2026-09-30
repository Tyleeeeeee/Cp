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
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,res,dp[5000][5000];
int main()
{
    fast_io;
    cin>>n;
    ll a[n],b[n];
    res=0;
    for(auto&v:a)cin>>v;
    for(int q=0;q<n;++q){
        cin>>b[q];
        res+=b[q]*a[q];
    }
    if(n>1){
        memset(dp,0,sizeof(dp));
        for(int l=1;l<=n;++l){
            for(int i=0;i+l-1<n;++i){
                dp[i][i+l-1]=(l==1?a[i]*b[i]:l==2?a[i]*b[i+1]+a[i+1]*b[i]:a[i]*b[i+l-1]+a[i+l-1]*b[i]+dp[i+1][i+l-2]);
            }
        }
        ll pref[n],surf[n];
        for(int q=0;q<n;++q){
            pref[q]=a[q]*b[q]+(q?pref[q-1]:0);
            surf[n-q-1]=a[n-q-1]*b[n-q-1]+(n-q-1<n-1?surf[n-q]:0);
        }
        for(int q=0;q<n;++q){
            for(int w=q+1;w<n;++w){
                res=max(res,(q?pref[q-1]:0)+(w<n-1?surf[w+1]:0)+dp[q][w]);
            }
        }
    }
    cout << res << "\n";
}

/*
   author :tlx
               */









