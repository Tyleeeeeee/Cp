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

int main()
{
    fast_io;
    string e,p,k;
    e="NSLOWYLCIMWFFET";
    k="persona";
    ll l=k.length();
    for(int q=0;q<e.length();++q){
        p+=((e[q]-'A'-(k[q%l]-'a'))+26)%26 + 'a';
    }
    cout << p << "\n";
}

