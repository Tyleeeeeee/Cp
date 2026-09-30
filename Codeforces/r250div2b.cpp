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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll s,lm,res;
int main()
{
    fast_io;
    ll sm;
    cin>>s>>lm;
    sm=0;
    vector<ll> ans,arr(lm+1);
    for(ll q=1;q<=lm;++q){
        ll x,tmp;
        x=0,tmp=q;
        while(!(tmp&1)) x++,tmp>>=1;
        sm+=(1<<x),arr[q]=(1<<x);
    }
    if(s>sm) res=-1;
    else{
        for(ll q=lm&1?lm-1:lm;q && s;q-=2) if(s>=arr[q]) s-=arr[q],ans.push_back(q);
        for(ll q=1;q<=lm && s;q+=2) s-=arr[q],ans.push_back(q);
        res=ans.size();
    }
    cout << res << "\n";
    if(res!=-1){for(auto&v:ans)cout << v << " "; cout << "\n";}
}
/*
   author :tlx
               */

