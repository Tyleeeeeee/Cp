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

ll t,n,x,y,a,b,k,res,p[200001];
ll gcd(ll i,ll j){while(i%=j)swap(i,j); return j;}
ll lcm(ll i,ll j){return (i*j/gcd(i,j));}
void solve(){
    ll i,j,mid;
    i=1,j=n;
    while(i<=j){
        mid=(i+j)/2;
        ll cost,up,r0,r1,r2;
        cost=0,r0=mid/lcm(a,b),r1=mid/(x>y?a:b)-r0,r2=mid/(x>y?b:a)-r0;
        for(int q=1;q<=r0;++q) cost+=p[q]*(x+y)/100;
        for(int q=r0+1;q<=r0+r1;++q) cost+=p[q]*(x>y?x:y)/100;
        for(int q=r0+r1+1;q<=r0+r1+r2;++q) cost+=p[q]*(x>y?y:x)/100;
        if(cost>=k) res=min(res,mid),j=mid-1;
        else i=mid+1;
    }
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        for(int q=1;q<=n;++q)cin>>p[q];
        cin>>x>>a>>y>>b>>k;
        sort(p+1,p+n+1,[](ll i,ll j){return i>j;});
        res=inf;
        solve();
        cout << (res==inf?-1:res) << "\n";
    }
}
/*
   author :tlx
               */

