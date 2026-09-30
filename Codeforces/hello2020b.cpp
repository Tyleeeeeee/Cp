#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;
using ll = long long ;

ll n,ans;
pair<ll,pair<ll,ll>> arr[100000];
ll bns(ll fd)
{
    ll i,j,mid;
    i=0;j=n-1;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid].first<=fd) j=mid-1;
        else i=mid+1;
    }
    return i;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    ans=0;
    memset(arr,0,sizeof(arr));
    for(int q=0;q<n;++q){
        ll l,cur,pre,ct=0;
        cin>>l;
        for(int w=0;w<l;++w){
            cin >> cur;
            if(!w) arr[q].first=cur;
            if(w==l-1) arr[q].second.first=cur;
            if(w>0) ct+=cur>pre;
            pre=cur;
        }
        arr[q].second.second=ct>0;
    }
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    sort(arr,arr+n,[](auto a,auto b){return a.first>b.first;});
    dp[n]=0;
    for(int q=n-1;q>=0;--q) dp[q]+=arr[q].second.second+dp[q+1];
    for(int q=0;q<n;++q){
        if(arr[q].second.second>0) ans+=n;
        else ans+=bns(arr[q].second.first)+dp[bns(arr[q].second.first)];
    }
    cout << ans << "\n";
}

