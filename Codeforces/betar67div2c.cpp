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

ll a,b,n,l,h,d,res;
vector<ll> factor;
void solve(){
    ll i,j,mid;
    i=0,j=factor.size()-1;
    while(i<=j){
        mid=(i+j)/2;
        if(factor[mid]<=h) i=mid+1;
        else j=mid-1;
    }
    if(factor[j]>=l) res=factor[j];
}
int main()
{
    fast_io;
    auto gcd=[](ll a,ll b){while(a%=b)swap(a,b); return b;};
    cin>>a>>b>>n;
    d=gcd(a,b);
    for(int q=1;q<=sqrt(d);++q){
         if(d%q==0){
            factor.push_back(q);
            if(d/q!=q) factor.push_back(d/q);
        }
    }
    sort(factor.begin(),factor.end());
    for(int q=0;q<n;++q){
        cin>>l>>h;
        res=-1;
        if(d>=l && d<=h) res=d;
        else solve();
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

