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

ll n,x,y,z,res;
string s;
int main()
{
    fast_io;
    char l='1';
    cin>>n>>x>>y>>s;
    res=z=0;
    if(s.find('0')==string::npos) res=0;
    else if(s.find('1')==string::npos) res=y;
    else for(ll q=0;q<n;++q){ if(l=='1' && s[q]=='0') z++; l=s[q];}
    if(z) res=(z-1)*min(x,y)+y;
    cout << res << "\n";
}

