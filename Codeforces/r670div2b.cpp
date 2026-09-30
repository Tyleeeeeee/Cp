#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    long long ans,mx;
    cin>>t;
    while(t--&&cin>>n)
    {
        mx=-1e18;
        int arr[n];
        for(auto&v:arr)cin>>v;
        sort(arr,arr+n);
        for(int q=0;q<6;++q)
        {
            ans=1;
            int i=q,j=5-q;
            while(i) ans*=arr[n-(i--)];
            while(j) ans*=arr[(j--)-1];
            mx=max(mx,ans);
        }
        cout << mx << "\n";
    }
}

