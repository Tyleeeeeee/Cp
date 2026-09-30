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
#include<set>
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll res;
string s[2];
int main()
{
    fast_io;
    res=0;
    cin>>s[0]>>s[1];
    for(int q=0;q<s[0].length();++q){
        ll ok=0;
        if(!(s[0][q]=='0' && s[1][q]=='0')) continue;
        if(q>0){
            if(s[0][q-1]=='0') s[0][q-1]='X',res++,ok=1;
            else if(s[1][q-1]=='0') s[1][q-1]='X',res++,ok=1;
        }
        if(q<s[0].length()-1 && !ok){
            if(s[0][q+1]=='0') s[0][q+1]='X',res++,ok=1;
            else if(s[1][q+1]=='0') s[1][q+1]='X',res++,ok=1;
        }
        if(ok) s[0][q]=s[1][q]='X';
    }
    cout << res << "\n";
}
/*
   author :tlx
               */



