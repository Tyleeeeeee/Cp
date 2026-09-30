#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long bns(long long *arr,int n,long long fd)
{
    int i=0,j=n-1,mid;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]>fd) j=mid-1;
        else i=mid+1;
    }
    return n-i;
}
int main()
{
    int t,n;
    long long k;
    cin>>t;
    while(t--&&cin>>n){long long arr[n]; vector<long long>ans; k=0;
        for(int q=0;q<n;++q){
            cin>>arr[q];
            if(arr[q]>=q+1) arr[q]=-1;
            else ans.push_back(q+1);
        }
        sort(arr,arr+n);
        for(int q=0;q<ans.size();++q){
            k+=bns(arr,n,ans[q]);
        }
        cout << k << "\n";
    }
}


