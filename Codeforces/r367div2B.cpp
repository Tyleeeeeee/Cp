#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100001]={0};

int bns(int i,int j,long long fn)
{
    int mid;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(arr[mid]<=fn) i=mid+1;
        else j=mid-1;
    }
    return i;
}
int main()
{
    int n,q;
    cin>>n;
    for(int i=0;i<n;++i)cin>>arr[i];
    cin>>q;
    vector<long long> pr(q);
    for(auto&v:pr) cin>>v;
    sort(arr,arr+n);
    for(int w=0;w<q;++w)
    {
        cout << bns(0,n-1,pr[w]) << "\n"; 
    }
}

