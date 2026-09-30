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

ll a,b,k,res,dp[1000001];
void solve(){
    ll i,j,mid;
    i=k,j=b-a+1;
    while(i<=j){
        mid=(i+j)/2;
        ll ok;
        ok=1;
        for(int q=a;q+mid-1<=b && ok;++q) if(dp[q+mid-1]-dp[q-1] < k) ok=0;
        if(ok) res=min(res,mid),j=mid-1;
        else i=mid+1;
    }
}
int main()
{
    fast_io;
    auto isprime=[](ll n){
        if(n>1 && n<4) return 1;
        if(!(n&1) || !(n%3)) return 0;
        for(int q=5;q<=sqrt(n);q+=6) if(!(n%q) || !(n%(q+2))) return 0;
        return 1;
    };
    memset(dp,0,sizeof(dp));
    dp[2]=1;
    for(int q=3;q<=1e6;++q) dp[q]=dp[q-1]+isprime(q);
    cin>>a>>b>>k;
    res=inf;
    if(dp[b]-dp[a-1] < k) res=-1;
    else solve();
    cout << res << "\n";
}
/*
   author :tlx
               */



