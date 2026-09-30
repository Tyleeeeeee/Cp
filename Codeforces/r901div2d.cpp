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

ll t,n,res,dp[5001],c[5000];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        memset(c,0,sizeof(c));
        ll a[n],mex; 
        for(auto&v:a){
            cin>>v;
            if(v<5000) c[v]++;
        }
        mex=0;
        while(c[mex]) mex++;
        if(!mex) res=mex;
        else{
            memset(dp,0x7F,sizeof(dp));
            dp[mex]=0;
            for(int q=mex;q>=0;--q) for(int w=q-1;w>=0;--w) dp[w]=min(dp[w],dp[q]+(c[w]-1)*q+w);
            res=dp[0];
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */





