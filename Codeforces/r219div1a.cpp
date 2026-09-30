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

ll n,res;
int main()
{
    fast_io;
    cin>>n;
    ll s[n]; for(auto&v:s)cin>>v;
    sort(s,s+n,[](ll a,ll b){return a>b;});
    ll lp,rp,st;
    st=n/2,lp=0,rp=st,res=n;
    while(lp<st && rp<n){
        if(s[lp]>=s[rp]*2) res--,lp++;
        rp++;
    }
    cout << res << "\n";
}
/*
   author :tlx
               */



