#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
using ll=long long;

int main()
{
    ll t,n;
    string ans;
    cin>>t;
    while(t--&&cin>>n){ ans.clear();
        while(n){
            if(n%9<4) ans+=n%9+'0';
            else ans+=n%9+'1';
            n/=9;
        }
        reverse(ans.begin(),ans.end());
        cout << ans << "\n";
    }
}

