#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
using ll=long long;
const ll mx=1e9+7;

ll dp[200001];
int main()
{
    ll t,n,ans;
    dp[0]=1;
    for(int q=1;q<200001;++q) dp[q]=(dp[q-1]*q)%mx;
    cin>>t;
    while(t--&&cin>>n){ ans=0;
        ll arr[n],mn,mnc;
        for(auto&v:arr)cin>>v;
        sort(arr,arr+n);
        mnc=0,mn=1e18;
        int ok;
        ok=1;
        for(ll x:arr){
            mn=min(mn,x);
            mnc+=(x==mn?1:0);
            if((x&mn)!=mn) {ok=0; break;}
        }
        if(mnc<2) ok=0;
        if(!ok) ans=0;
        else ans=(((mnc*(mnc-1))%mx)*dp[n-2])%mx;
        cout << ans << "\n";
    }
}


