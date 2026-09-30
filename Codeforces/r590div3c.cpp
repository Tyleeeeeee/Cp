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

ll t,n,ok;
string s[2];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>s[0]>>s[1]){
        ok=1;
        for(int q=0;q<2;++q)
            for(int w=0;w<n;++w)
                s[q][w]=(s[q][w]-'0'<3?'1':'0');
        if(s[0][n-1]=='1' && s[1][n-1]=='0') ok=0;
        else{
            ll pos;
            pos=0;
            for(int q=0;q<n && ok;++q){
                if(q<n-1){
                    if(!pos && s[0][q]=='0' && s[1][q]=='1') ok=0;
                    if(pos && s[1][q]=='0' && s[0][q]=='1') ok=0;
                    if(s[0][q]=='0' && s[1][q]=='0') pos^=1;
                }else{
                    if(s[1][q]=='0') ok=(!pos?1:0);
                    if(s[1][q]=='1') ok=(pos?1:0);
                }
            }
        }
        cout << (ok?"YES":"NO") << "\n";
    }
}
/*
   author :tlx
               */



