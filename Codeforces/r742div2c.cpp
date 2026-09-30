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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t;
string s;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>s){
        ll a,b;
        a=b=0;
        //decimal-like system
        for(int q=0;q<s.length();++q) a=(a*10)+(s[q]-'0'),swap(a,b);
        cout << (a+1)*(b+1)-2 << "\n";
    }
}
/*
   author :tlx
               */





