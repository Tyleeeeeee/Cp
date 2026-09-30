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
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll n,m,res,dp[1001][1<<9];
void generate(vector<ll> &nextmask,ll mask,ll newmask,ll pos){
    if(pos==n) {nextmask.pb(newmask); return;}
    if(pos+1<n && !((1<<pos)&mask) && !((1<<(pos+1))&mask)) generate(nextmask,mask,newmask,pos+2);
    if(!((1<<pos)&mask)) generate(nextmask,mask,newmask+(1<<pos),pos+1);
    if((1<<pos)&mask) generate(nextmask,mask,newmask,pos+1);
}
ll solve(ll i,ll mask,ll pos){
    if(i==m) return !mask?1:0;
    if(dp[i][mask]!=-1) return dp[i][mask];
    ll sum;
    vector<ll> nextmask;
    sum=0;
    generate(nextmask,mask,0,0);
    for(ll x:nextmask){
        sum=(sum+solve(i+1,x,0))%mdl1;
    }
    dp[i][mask]=sum;
    return dp[i][mask];
}
int main()
{
    fast_io;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    res=((n&1) && (m&1)?0:solve(0,0,0));
    cout << res << "\n";
}
/*
   author :tlx
               */

