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

string s1,s2;
int main()
{
    fast_io;
    ll t,ans;
    cin>>t;
    while(t--&&cin>>s1>>s2){
        ll n,m;
        n=s1.length(),m=s2.length();
        if(m>n) ans=0;
        else{
            ll prty,ok,fp;
            fp=ok=0,prty=(n-m)&1;
            for(int q=prty;q<n;q++){
                if(ok) ok=0;
                else if(s1[q]==s2[fp]) fp++;
                else ok=1;
            }
            ans=(fp==m);
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}

