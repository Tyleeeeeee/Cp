#include<iostream>
using namespace std;

int main()
{
    int t,n,max;
    cin>>t;
    while(t--&&cin>>n){ max=0;
        int dp[n+1];
        long long arr[n+1];
        for(int q=1;q<n+1;++q)cin>>arr[q];
        for(auto&v:dp)v=1;
        for(int q=1;q<n+1;++q){
            for(int w=q*2;w<n+1;w+=q){
                if(arr[q]<arr[w]) dp[w]=dp[w]<dp[q]+1?dp[q]+1:dp[w];
            }
        }
        for(int q=1;q<n+1;++q) max=max<dp[q]?dp[q]:max;
        cout << max << "\n";
    }
}

