#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{
    int t,n,k,ans;
    cin>>t;
    while(t--&&cin>>n>>k){int arr[n]; ans=0;
        for(auto&v:arr)cin>>v;
        sort(arr,arr+n,[](int a,int b){return a>b;});
        for(int q=0;q<n;++q){
            if(q>=0 && q<=k-1){
                ans+=(arr[q+k]/arr[q]);
            }
            if(q>2*k-1) ans+=arr[q];
        }
        cout << ans << "\n";
    }
}

