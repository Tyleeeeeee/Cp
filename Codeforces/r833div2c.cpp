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

ll t,n,res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll a[n],sum,ok,good;
        map<ll,ll> mp;
        good=ok=sum=res=mp[0]=0;
        memset(a,0,sizeof(a));
        for(int q=0;q<n;++q){
            cin>>a[q];
            if(!a[q]){
                good=1;
                if(!ok) res+=mp[0],ok=1;
                else res+=(max_element(mp.begin(),mp.end(),[](auto a,auto b){return a.second<b.second;}))->second;
                mp.clear();
            }
            sum+=a[q],mp[sum]++;
        }
        ok=0;
        for(int q=n-1;q>=0 && !ok;--q)if(!a[q]) res+=(max_element(mp.begin(),mp.end(),[](auto a,auto b){return a.second<b.second;}))->second,ok=1;
        if(!good) res=mp[0];
        cout << res << "\n";
    }
}

/*
   author :tlx
               */









