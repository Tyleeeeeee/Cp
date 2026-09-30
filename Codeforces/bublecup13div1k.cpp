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

ll t,n,res;
vector<ll> ps,p(MAX);
void solve(){
    ll i,j,mid;
    i=0,j=ps.size()-1;
    while(i<=j){
        mid=(i+j)/2;
        if(ps[mid]*ps[mid]<=n) i=mid+1;
        else j=mid-1;
    }
    res-=(j+1);
}
int main()
{
    fast_io;
    p[0]=p[1]=0;
    for(int q=2;q<MAX;++q) p[q]=1;
    for(int q=2;q*q<MAX;++q){
        if(p[q]) {for(int w=q*q;w<MAX;w+=q) p[w]=0;}
    }
    // p[2]=0;
    for(int q=1;q<MAX;++q) if(p[q]) ps.push_back(q);
    partial_sum(p.begin(),p.end(),p.begin());
    cin>>t;
    while(t--&&cin>>n){
        res=p[n]+1;
        solve();
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

