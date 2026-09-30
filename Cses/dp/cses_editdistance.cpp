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

ll dp[5001][5001];
string s1,s2;
int main()
{
    fast_io;
    cin>>s1>>s2;
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    for(int q=1;q<=s2.length();++q) dp[0][q]=q;
    for(int q=1;q<=s1.length();++q) dp[q][0]=q;
    for(int q=1;q<=s1.length();++q){
        for(int w=1;w<=s2.length();++w){
            if(s1[q-1]==s2[w-1]) dp[q][w]=dp[q-1][w-1];
            else dp[q][w]=min(dp[q-1][w-1],min(dp[q-1][w],dp[q][w-1]))+1;
        }
    }
    // for(int q=1;q<=s1.length();++q){
    //     for(int w=1;w<=s2.length();++w) cout << dp[q][w] << " ";
    //     cout << "\n";
    // }
    cout << dp[s1.length()][s2.length()] << "\n";
}
/*
   author :tlx
               */

