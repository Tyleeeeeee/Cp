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

ll res,a,b,c;
string s;
int main()
{
    fast_io;
    cin>>s;
    a=b=c=res=0;
    for(int q=0;q<s.length();++q){
        if(s[q]=='b'){ c=res,b++; continue;}
        if(s[q]=='a'){
            if(b) a+=(res+1)%mdl;
            else a+=(c+1)%mdl;
        }
        if(q+1<s.length() && s[q]=='a' && s[q+1]!='a') res+=a,a=0,b=0;
    }
    res+=(a?a:0);
    cout << res%mdl << "\n";
}
/*
   author :tlx
               */



