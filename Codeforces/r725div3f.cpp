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
    ll t,l,r,ans;
    cin>>t;
    while(t--&&cin>>l>>r){
        ans=0;
        while(l||r){
            ans+=r-l;
            r/=10,l/=10;
        }
        cout << ans << "\n";
    }
}

