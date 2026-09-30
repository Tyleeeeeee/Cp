#include<iostream>
#include<algorithm>
using namespace std;

long long arr[200000];
long long solve(long long n,long long k)
{
    long long i,j,mid,median;
    median=arr[(n+1)/2-1];
    while(k>0){
        i=0,j=n-1;
        while(i<=j) {
            mid=(i+j)/2;
            if(arr[mid]<=arr[(n+1)/2 - 1]) i=mid+1;
            else j=mid-1;
        }
        if(i==n){median+=k/(i-(n+1)/2+1),k-=k;} 
        else{
            if((arr[i]-median)*(i-(n+1)/2+1)>k){median=median+k/(i-(n+1)/2+1),k-=k;}
            else {
                k-=(arr[i]-median)*(i-(n+1)/2+1),median=arr[i];
                for(int q=(n+1)/2-1;q<i;++q) arr[q]=arr[i];
            }
        }
    }
    return median;
}
int main()
{
    long long n,k,ans;
    cin>>n>>k;
    for(int q=0;q<n;++q)cin>>arr[q];
    sort(arr,arr+n);
    if(n==1) ans=arr[0]+k;
    else ans=solve(n,k);
    cout << ans << "\n";
}


