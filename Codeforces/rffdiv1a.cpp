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

ll n,res;
int main()
{
    fast_io;
    cin>>n;
    res=0;
    ll a[n]; for(auto&v:a)cin>>v;
    ll pref[n],surf[n];
    for(int q=0;q<n;++q) pref[q]=surf[q]=1;
    for(int q=0;q<n;++q){
        if(q && a[q]>a[q-1]) pref[q]=pref[q-1]+1;
        if(q && a[n-q-1]<a[n-q]) surf[n-q-1]=surf[n-q]+1;
    }
    res=max(surf[1]+1,pref[n-2]+1);
    for(int q=1;q+1<n;++q){
        res=max(res,max(pref[q-1]+1,surf[q+1]+1));
        if(a[q-1]+1<a[q+1]) res=max(res,pref[q-1]+1+surf[q+1]);
    }
    res=(n<3?n:res);
    cout << res << "\n";
}
/*
   author :tlx
               */





