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

string s1,s2;
ll a,al,b,bl,dp[20][10][2][2],res;//dp[cur][prev][leadingzero][tight]//digit dp
ll dfs(string &s,ll cur,ll prev,ll ldz,ll tight){
    if(!cur) return 1;
    if(dp[cur][prev][ldz][tight]!=-1) return dp[cur][prev][ldz][tight];
    ll limit,sum;
    sum=0;
    if(tight) limit=s[s.length()-cur]-'0';
    else limit=9;
    for(int q=0;q<=limit;++q){
        if(!ldz && q==prev) continue;
        ll new_ldz=(ldz && !q)?1:0;
        ll new_tight=(tight && q==limit)?1:0;
        sum+=dfs(s,cur-1,q,new_ldz,new_tight);
    }
    dp[cur][prev][ldz][tight]=sum;
    return dp[cur][prev][ldz][tight];
}
int main()
{
    fast_io;
    cin>>a>>b;
    res=0;
    memset(dp,-1,sizeof(dp));
    s1=to_string(b);
    res+=dfs(s1,s1.length(),-1,1,1);
    memset(dp,-1,sizeof(dp));
    s2=to_string(a-1);
    res-=dfs(s2,s2.length(),-1,1,1);
    cout << res << "\n";
}
/*
   author :tlx
               */

