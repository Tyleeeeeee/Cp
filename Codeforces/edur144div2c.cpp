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
const ll mmdl=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX 1000001 //1e6+1

ll t,l,r,res;
ll solve(ll lg){
    ll i,j,mid;
    i=l,j=r;
    while(i<=j){
        mid=(i+j)/2;
        if(mid*(1<<(lg-1))<=r) i=mid+1;
        else j=mid-1;
    }
    return i;
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>l>>r){
        ll lg,x;
        res=lg=0;
        for(int i=0;l*(1<<i)<=r;++i) lg++;
        x=(1LL<<(lg-2)),res+=(solve(lg)-l+max(0LL,((r/(3*x))-l+1)*(lg-1)))%mmdl;
        cout << lg << " " << res << "\n";
    }
}
/*
   author :tlx
               */



