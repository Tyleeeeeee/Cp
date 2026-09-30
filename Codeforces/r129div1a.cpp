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

ll l,r;
int main()
{
    fast_io;
    auto solve=[](ll n){
        if(n<10) return n;
        else{
            ll res=n/10+9,x=n;
            while((x/=10)>=10);
            if(x>n%10) res--;
            return res;
        }
    };
    cin>>l>>r;
    cout << solve(r)-solve(l-1) << "\n";
}
/*
   author :tlx
               */

