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
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,m;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>m){
        ll ub,lb,ok,ti,tp,lf,rg;
        ok=1,tp=0,ub=lb=m;
        while(n-- && cin>>ti>>lf>>rg){
            if(!ok) continue;
            ub+=ti-tp,lb-=ti-tp,tp=ti;
            if(ub<lf || lb>rg) ok=0;
            else ub=min(ub,rg),lb=max(lb,lf);
        }
        cout << (ok?"YES":"NO") << "\n";
    }
}
/*
   author :tlx
               */

