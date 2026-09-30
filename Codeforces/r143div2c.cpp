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
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,k,rl,res,a[100000],pref[100000];
void solve(ll i,ll j){
    ll mid,ta;
    ta=j+1;
    while(i<=j){
        mid=(i+j)/2;
        if((a[ta]*(ta-mid)-pref[ta-1]+(mid>0?pref[mid-1]:0))<=k) {if(ta-mid+1>rl) rl=ta-mid+1,res=a[ta]; j=mid-1;}
        else i=mid+1;
    }
}
int main()
{
    fast_io;
    cin>>n>>k;
    for(int q=0;q<n;++q)cin>>a[q];
    sort(a,a+n);
    rl=res=0;
    memset(pref,0,sizeof(pref));
    for(int q=0;q<n;++q){
        if(q) pref[q]+=a[q]+pref[q-1],solve(0,q-1);
        else rl=1,res=pref[q]=a[q];
    }
    cout << rl << " " << res << "\n";
}
/*
   author :tlx
               */



