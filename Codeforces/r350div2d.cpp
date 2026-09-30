#include<iostream>
#include<algorithm>
using namespace std;

int arr[2][1000];
int solve(int n, int k) //binary search
{
    int i,j,mid,tmp;
    i=0,j=2000;
    while(i<=j){ tmp=0;
        mid=(i+j)/2;
        for(int q=0;q<n;++q) tmp+=max(0,mid*arr[0][q]-arr[1][q]);
        if(tmp<=k) i=mid+1;
        else j=mid-1;
    }
    return j;
}
int main()
{
    int n,k,ans;
    cin>>n>>k;
    for(int q=0;q<2;++q) for(int w=0;w<n;++w) cin>>arr[q][w];
    ans=solve(n,k);
    cout << ans << "\n";
}

