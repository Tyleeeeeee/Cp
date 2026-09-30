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

ll a,m,k;
int main()
{
    fast_io;
    cin>>a;
    if(a<3) m=-1;
    else m=(a&1?(a*a+1)/2:(a*a/4+1)),k=(a&1?(a*a-1)/2:(a*a/4-1));
    if(m==-1) cout << m << "\n";
    else cout << m << " " << k << "\n";
}

