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

ll n,res;
int main()
{
    fast_io;
    res=0;
    cin>>n;
    res=n-(n/2)-(n/3)-(n/5)-(n/7)+(n/6)+(n/10)+(n/15)-(n/30)+(n/14)+(n/21)-(n/42)+(n/35)-(n/70)-(n/105)+(n/210);
    cout << res << "\n";
}

