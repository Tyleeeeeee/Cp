#include<iostream>
using namespace std;

long long arr[200000][2],n;
long long solve(long long mx)
{
    long long i,j,mid,rx,ry,tmp,ans;
    ans=1e18;
    i=0,j=mx;
    while(i<=j){ 
        mid=(i+j)/2;
        tmp=rx=0,ry=mid;
        for(int q=0;q<n;++q){
            if(arr[q][0]>ry || arr[q][1]<rx) {tmp=-1; break;}
            else {
                if(arr[q][0]>=rx) rx=arr[q][0];
                if(arr[q][1]<=ry) ry=arr[q][1];
            }
            rx=(rx-mid<=0?0:rx-mid);
            ry=ry+mid;
        }
        if(tmp==-1) i=mid+1;
        else {j=mid-1,ans=ans>mid?mid:ans;}
    }
    return ans;
}
int main()
{
    long long t,mx;
    cin>>t;
    while(t--&&cin>>n){ mx=0;
        for(int q=0;q<n;++q)
            cin>>arr[q][0]>>arr[q][1],mx=mx<arr[q][1]?arr[q][1]:mx;
        cout << solve(mx) << "\n";
    }
}

