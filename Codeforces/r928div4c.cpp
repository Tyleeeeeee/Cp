#include<iostream>
using namespace std;

int main()
{
    int t,n;
    long long dp[200001];
    auto dgs=[](int n)
    {
        int ans=0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    };
    dp[1]=1;
    for(int q=2;q<200001;++q)
    {
        dp[q]=dp[q-1]+dgs(q);
    }
    cin>>t;
    while(t--&&cin>>n)
    {
        cout << dp[n] << "\n";
    }
}

