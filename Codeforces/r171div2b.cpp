#include<iostream>
using namespace std;

int arr[100000];
int main()
{
    long long t,n,lp,rp,ans,tmp;
    cin>>n>>t;
    tmp=ans=lp=rp=0;
    for(int q=0;q<n;++q) cin>>arr[q];
    for(;rp<n;++rp){
        tmp+=arr[rp];
        while(tmp>t){
            tmp-=arr[lp++];
        }
        ans=rp-lp+1>ans?rp-lp+1:ans;
    }
    cout << ans << "\n";
}



