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

ll x,a;
int main()
{
    fast_io;
    auto gcd=[](ll c,ll d){
        while(c%=d) swap(c,d);
        return d;
    };
    auto lcm=[&gcd](ll c,ll d){
        return (c*d)/gcd(c,d);
    };
    cin>>x;
    for(ll q=1;q*q<=x;++q){
        if(x%q==0 && lcm(q,x/q)==x){
            a=q;
        }
    }
    cout << a << " " << x/a << "\n";
}

