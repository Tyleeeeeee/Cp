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
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t;
char c;
string s;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>c>>s){
        if(!(c-'0')) swap(s[0],s[6]),swap(s[1],s[7]),swap(s[2],s[4]),swap(s[3],s[5]);
        cout << s << "\n";
    }
}
/*
   author :tlx
               */



