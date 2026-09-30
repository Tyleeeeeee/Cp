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

ll n,res;
int main()
{
    fast_io;
    cin>>n;
    pair<ll,ll> ab[n];
    for(int q=0;q<n;++q) cin>>ab[q].second>>ab[q].first;
    sort(ab,ab+n);
    ll lp,rp,r2,r1;
    r1=r2=0;
    for(lp=0,rp=n-1;~rp && lp<=rp;){
        if(r1+r2+ab[rp].second<=ab[lp].first) r2+=ab[rp--].second;
        else{
            ll x=max(0LL,ab[lp].first-r1-r2);
            r2+=x,ab[rp].second-=x,r1+=ab[lp++].second;
        }
    }
    res=r1+r2*2;
    cout << res << "\n";
}
/*
   author :tlx
               */



