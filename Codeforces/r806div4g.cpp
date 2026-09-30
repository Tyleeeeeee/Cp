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

ll t,n,k,res,a[100000];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>k){
        for(int q=0;q<n;++q) cin>>a[q];
        vector<ll> pref(n);
        for(int q=0;q<n;++q) pref[q]=a[q]-k;
        res=0;
        partial_sum(pref.begin(),pref.end(),pref.begin(),[](ll a,ll b){return a+b;});
        for(int q=-1;q<n;++q){
            ll sum=(q>=0?pref[q]:0);
            for(int w=q+1;w<min(q+33LL,n);++w){
                sum+=(a[w]>>(w-q));
            }
            res=max(res,sum);
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */





