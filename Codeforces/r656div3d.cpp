#include<iostream>
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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,mn;
string s;
void solve(char ch,ll i,ll j,ll ans){
    if(i==j){if(s[i]!=ch) ans++; mn=min(mn,ans); return;}
    int lfcnt,rgcnt;
    lfcnt=rgcnt=0;
    for(int q=i;q<=(j-i)/2+i;++q) lfcnt+=(s[q]!=ch);
    for(int q=(j-i)/2+i+1;q<=j;++q) rgcnt+=(s[q]!=ch);
    solve(ch+1,(j-i)/2+i+1,j,ans+lfcnt);
    solve(ch+1,i,(j-i)/2+i,ans+rgcnt);
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>s){
        mn=1e18;
        solve('a',0,n-1,0);
        cout << mn << "\n";
    }
}
/*
   author :tlx
               */

