#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

string s;
int main()
{
    fast_io;
    cin>>s;
    int lp,rp,res,n,sum,cpy;
    n=s.length();
    for(res=sum=lp=rp=0;rp<n;++rp){
        sum+=(s[rp]-'0')%3;
        cpy=sum-(s[lp]-'0')%3;
        if(sum%3==0 || (s[rp]-'0')%3==0 || (rp-lp+1==3 && cpy%3==0)) sum=0,res++,lp=rp+1;
    }
    cout << res << "\n";
}

