#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int main()
{
    fast_io;
    ll n,one,zer;
    string s;
    cin>>n>>s;
    one=zer=0;
    for(char x:s) one+=(x=='1'),zer+=(x=='0');
    for(ll q=pow(2,one);q<=pow(2,n)-(pow(2,zer)-1);++q) cout << q << " ";
    cout << "\n";
}

