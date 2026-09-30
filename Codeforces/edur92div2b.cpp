#include<iostream>
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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,k,z,res,sum,arr[100001],pref[100001];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>k>>z){
        sum=res=0;
        for(int q=1;q<=n;++q) cin>>arr[q],sum+=(q<=k+1?arr[q]:0);
        pref[1]=arr[1]+arr[2];
        for(int q=2;q+1<=n;++q) pref[q]=max(arr[q]+arr[q+1],pref[q-1]);
        for(int q=0;q<=z;++q){
            if(k+1-2*q<1) continue;
            res=max(res,sum+q*(q?pref[k+1-2*q]:0));
            sum-=(arr[k+1-2*q]+arr[k-2*q]);
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */



