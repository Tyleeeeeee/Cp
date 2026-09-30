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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,arr[1000],ans[1000][1000];
int main()
{
    fast_io;
    cin>>n; for(int q=0;q<n;++q) cin>>arr[q];
    ll cnt,mx,mxi;
    mx=cnt=0;
    for(int q=0;q<n;++q){
        ll sum;
        sum=ans[cnt][q]=arr[q];
        for(int i=q-1;i>=0;--i) ans[cnt][i]=min(arr[i],ans[cnt][i+1]),sum+=ans[cnt][i];
        for(int i=q+1;i<n;++i) ans[cnt][i]=min(arr[i],ans[cnt][i-1]),sum+=ans[cnt][i];
        if(sum>mx) mx=sum,mxi=cnt;
        cnt++;
    }
    for(int q=0;q<n;++q) cout << ans[mxi][q] << " ";
    cout << "\n";
}
/*
   author :tlx
               */

