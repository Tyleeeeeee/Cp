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

string s1,s2;
int main()
{
    fast_io;
    ll res,x,y;
    cin>>s1>>s2;
    res=1,x=y=0;
    for(auto v:s1) x+=(v-'0');
    for(auto v:s2) y+=(v-'0');
    if(s1.length()!=s2.length()) res=0;
    else res^=(((x>0) ^ (y>0)));
    cout << (res?"YES":"NO") << "\n";
}

