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
ll t,n,dp[40001];
int main()
{
    fast_io;
    auto ispdr=[](ll k){
        string s=to_string(k);
        int ok=1,n=s.length();
        for(int q=0;q<s.length();++q) if(s[q]!=s[n-q-1]) ok=0;
        return ok;
    };
    vector<int> pdr;
    for(int q=1;q<=40000;++q) if(ispdr(q)) pdr.push_back(q);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int q=0;q<pdr.size();++q){
        for(int w=pdr[q];w<40001;++w)
            dp[w]=(dp[w]+dp[w-pdr[q]])%mdl;
    }
    cin>>t;
    while(t--&&cin>>n){
        //coin change problem
        cout << dp[n] << "\n";
    }
}

