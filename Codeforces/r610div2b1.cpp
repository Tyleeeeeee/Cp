#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long ;

ll dp[200000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t,n,p,k,ans;
    cin>>t;
    while(t--&&cin>>n>>p>>k){ ans=0;
        //ans1=odd ans2=even
        //try dp,dp has a general solution for k
        ll arr[n];
        for(auto&v:arr)cin>>v;
        sort(arr,arr+n);
        memset(dp,0,sizeof(dp));
        for(ll q=0;q<n;++q){
            if(!q) dp[q]=arr[q];
            else if(q<k-1) dp[q]=arr[q]+dp[q-1];
            else dp[q]=dp[q-k]+arr[q];
            if(dp[q]<=p) ans=max(ans,q+1);
        }
        cout << ans << "\n";
    }
}

