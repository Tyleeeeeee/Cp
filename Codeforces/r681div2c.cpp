#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    long long t,n,ans,sumMx;
    cin>>t;
    while(t--&&cin>>n){ ans=1e18,sumMx=0;
        pair<long long,long long> arr[n];
        for(int q=0;q<2;++q)
            for(int w=0;w<n;++w)
                if(!q)cin>>arr[w].first;
                else cin>>arr[w].second,sumMx+=arr[w].second;
        
        sort(arr,arr+n);
        for(int q=1;q<n;++q)
            arr[q].second+=arr[q-1].second;
        for(int q=0;q<n;++q){
            ans=min(ans,max(arr[q].first,arr[n-1].second-arr[q].second));
        }
        ans=min(ans,sumMx);
        cout << ans << "\n";
    }
}

