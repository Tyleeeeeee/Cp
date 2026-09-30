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

ll a,m,mx;
int main()
{
    fast_io;
    ll res,cnt;
    cin>>a>>m;
    res=0,cnt=20;
    while(cnt--){
        if(!(a%m)){res=1; break;}
        a+=(a%m);
    }
    cout << (res?"Yes":"No") << "\n";
}

