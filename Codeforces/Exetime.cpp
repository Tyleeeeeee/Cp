#include<iostream>
#include<algorithm>
using namespace std;

int n,T,ans;
int bns(int *arr,int fdi)
{
    int i,j,mid;
    i=0,j=n-1;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]<=arr[fdi]+T) i=mid+1;
        else j=mid-1;
    }
    return i-fdi;
}
int main()
{
    cin>>n;
    int arr[n];
    for(auto&v:arr)cin>>v;
    cin>>T;
    ans=0;
    sort(arr,arr+n);
    for(int q=0;q<n;++q){
        ans=max(ans,bns(arr,q));
    }
    cout << ans << "\n";
}

