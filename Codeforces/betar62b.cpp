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

ll n,k;
double a[10000];
double solve(){
    double i,j,mid,res;
    res=i=0,j=1e5;
    while(j-i>1e-9){
        mid=(i+j)/2;
        double l,r;
        l=r=0;
        for(int q=0;q<n;++q) r+=(a[q]>mid?a[q]-mid:0),l+=(a[q]<mid?mid-a[q]:0);
        r-=(k*r)/100;
        if(r-l>=0) i=mid,res=max(res,mid);
        else j=mid;
    }
    return res;
}
int main()
{
    fast_io;
    cin>>n>>k;
    for(int q=0;q<n;++q)cin>>a[q];
    cout << fixed << setprecision(6) << solve() << "\n";
}
/*
   author :tlx
               */



