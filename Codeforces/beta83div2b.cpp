#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;

ll n,arr[100000];
ll bns(ll k)
{
    ll i,j,mid;
    i=0,j=n-1;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]>k) j=mid-1;
        else i=mid+1;
    }
    if(i==n) i=n-1;
    return arr[i];
}
int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    cin>>n;
    for(int q=0;q<n;++q)cin>>arr[q];
    sort(arr,arr+n);
    int ok;
    ok=0;
    for(int q=0;q+1<n;++q){
        if(arr[q]*2>bns(arr[q]) && bns(arr[q])!=arr[q]){ok=1; break;}
    }
    cout << (ok?"YES":"NO") << "\n";
}

