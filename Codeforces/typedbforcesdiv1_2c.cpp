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

ll t,n,s,dp[200000][2];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>s){
        ll tmp,xpre,ypre,x,y;
        memset(dp,0,sizeof(dp));
        for(int q=0;q<n;++q){
            cin>>tmp;
            if(q){
                x=(q==n-1?tmp:tmp<=s?0:s),y=(q==n-1?tmp:tmp-x);
                //0 = x+y 1=y+x
                dp[q][0]=min(dp[q-1][0]+ypre*x,dp[q-1][1]+xpre*x);
                dp[q][1]=min(dp[q-1][0]+ypre*y,dp[q-1][1]+xpre*y);
            }
            xpre=(!q?tmp:x),ypre=(!q?tmp:y);
        }
        cout << min(dp[n-1][0],dp[n-1][1]) << "\n";
    }
}

/*
   author :tlx
               */









