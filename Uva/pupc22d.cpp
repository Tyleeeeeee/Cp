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

ll t,n,m,d;
double res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>m>>d){
        res=0;
        ll mmm,cr,tmp,k;
        mmm=(1LL<<n),cr=k=tmp=0;
        while((k+1)*(k+1)<mmm) k++;
        for(ll pos=m-1;tmp<=k;){
            if(pos*tmp<mmm) cr+=pos-tmp+1,tmp++;
            else pos=mmm/tmp-!(mmm%tmp);
        }
        cr=cr*2-k-1;
        res=cr/((double)m*(double)m);
        res=trunc(res*pow(10,d))/pow(10,d);
        cout << fixed << setprecision(d) << res << "\n";
    }
}
/*
   author :tlx
               */



