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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,a,b,tmp;
int main()
{
    fast_io;
    cin>>n>>a>>b;
    while(n--&&cin>>tmp){
        cout << (ll)(tmp-ceil((double)(tmp*a/b)*b/a)) << " ";
    }
    cout << "\n";
}
/*
   author :tlx
               */

