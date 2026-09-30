#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

const ll mdl=1e9+7;
ll t,n,m,l,r,x,ans;
ll solve()
{
    ll a,b,res;
    a=n-1,b=2,res=1;
    while(a){
        if(a&1) res=(res*b)%mdl;
        b=(b*b)%mdl;
        a/=2;
    }
    return (res*ans)%mdl;
}
int main()
{
    fast_io;
    //a1 a2 ... an ->k th bit is 0 then xor subsequence k th bit also 0
    //Assume that there is m ak k th bit is 1,then will have n-m k th bit is 0
    //mC0 + mC1 + mC2 +... +mCm = 2^m, sum of mCi which i is odd is 2^(m-1)
    //therefore the subsequece which k th bit is 1 is 2^(n-m) * 2^(m-1) = 2^(n-1)
    //contribute of k th bit to sum is 2^k * 2^(n-1)
    cin>>t;
    while(t--&&cin>>n>>m){
        ans=0;
        while(m--&&cin>>l>>r>>x) ans|=x;
        cout << solve() << "\n";
    }
}

