#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int t,n;
    long long dp[100001],arr[100001],srt[100001],ans;
    auto bns=[&srt,&n](long long N)
    {
        int i=0,j=n-1,mid;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(srt[mid]>N) j=mid-1; 
            else i=mid+1;
        }
        return i;
    };
    cin>>t;
    while(t--&&cin>>n)
    {
        memset(dp,0LL,sizeof(dp));
        for(int q=0;q<n;++q)
            cin>>arr[q],srt[q]=arr[q];
        sort(srt,srt+n);
        dp[1]=srt[0];
        for(int q=1;q<n;++q)
            dp[q+1]=dp[q]+srt[q];
        for(int q=0;q<n;++q)
        {
            ans=bns(arr[q]);
            while(bns(dp[ans])!=ans)ans=bns(dp[ans]);
            if(!q)cout << ans-1;
            else cout << " " << ans-1;
        }
        cout << "\n";
    }
}

