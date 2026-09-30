#include<iostream>
#include<utility>
#include<cstring>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int main()
{
    fast_io;
    ll t,n,k,ans;
    cin>>t;
    while(t--&&cin>>n>>k){
        ll odd;
        odd=n/2+n%2;
        if(k<=odd) ans=2*k-1;
        else{
            ll i,sum,ok;
            k-=odd,ok=1;
            for(i=1;ok;++i){
                sum=(n>>(i+1)) + ((n>>i) & 1);
                if(k<=sum) ans=(2*k-1)<<i,ok=0;
                else k-=sum;
            }
        }
        cout << ans << "\n";
    }
}

