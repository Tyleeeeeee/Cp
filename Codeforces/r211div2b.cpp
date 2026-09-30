#include<iostream>
using namespace std;

int main()
{
    int n,k,min=0x16161616,mindx;
    cin>>n>>k;
    int arr[n],dp[n+1];
    for(auto&v:arr) cin>>v;
    if(n==k) cout << 1 << "\n";
    else
    {
    dp[n-k+1]=0;
    for(int q=n-k;q<n;++q) dp[n-k+1]+=arr[q];
    if(dp[n-k+1]<min){min=dp[n-k+1],mindx=n-k+1;}
    for(int q=n-k;q>=1;--q)
    {
        dp[q]=dp[q+1]+arr[q-1]-arr[q+k-1];
        if(dp[q]<min){min=dp[q],mindx=q;}
    }
    cout << mindx << "\n";
    }
}

