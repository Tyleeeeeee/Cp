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

ll n,tmp,mx,sum;
int main()
{
    fast_io;
    cin>>n;
    sum=mx=0;
    while(n--&&cin>>tmp)sum+=tmp,mx=max(mx,tmp);
    cout << (mx<=sum-mx && ((sum&1)^1)?"YES":"NO") << "\n";
}

