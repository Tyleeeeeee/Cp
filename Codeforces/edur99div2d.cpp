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

ll t,n,x,res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>x){
        ll a[n]; for(auto&v:a)cin>>v;
        if(is_sorted(a,a+n)) res=0;
        else{
            ll cnt,ok;
            cnt=ok=0;
            for(int q=0;q+1<n && !ok;++q){
                if(a[q]>x) swap(a[q],x),cnt++;
                if(is_sorted(a,a+n)) ok=1;
            }
            res=ok?cnt:-1;
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */





