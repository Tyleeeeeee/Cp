#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

using ll=long long;

ll arr[2000],n;

ll solve(ll N)
{
    ll i,j,k,l,mid,ans;
    i=0,j=n-1;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]<=N) i=mid+1;
        else j=mid-1;
    }
    if(j==-1) ans=min(N,abs(arr[0]-N));
    else if(i==n) ans=abs(arr[n-1]-N);
    else ans=min(abs(arr[i]-N),abs(arr[j]-N));
    return ans;
}
int main()
{
    ll t,k,ans,dup,mn;
    cin>>t;
    while(t--&&cin>>n>>k){ dup=0;
        for(int q=0;q<n;++q) cin>>arr[q];
        if(k>2) ans=0;
        else{
           sort(arr,arr+n);
           for(int q=0;q+1<n;++q) dup+=(arr[q]==arr[q+1]);
           if(dup) ans=0;
           else{ mn=arr[0];
               if(k==1){for(int q=0;q+1<n;++q) {mn=mn>abs(arr[q]-arr[q+1])?abs(arr[q]-arr[q+1]):mn;} ans=mn;}
               if(k==2){ ans=1e18;
                   for(int q=0;q<n;++q){
                       for(int w=q+1;w<n;++w){
                           //abs(arr[q]-arr[w])
                           ans=ans>solve(abs(arr[q]-arr[w]))?solve(abs(arr[q]-arr[w])):ans;
                       }
                   }
               }
           }
        }
        cout << ans << "\n";
    }
}

