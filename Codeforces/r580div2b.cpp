#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int n,nve=0,zero=0;
    cin>>n;
    long long arr[n],ans=0;
    for(auto&v:arr)cin>>v;
    for(int q=0;q<n;++q){
        if(!arr[q]) zero++;
        else if(arr[q]<0){nve++; ans+=-1-arr[q];}
        else if(arr[q]>0){ans+=arr[q]-1;}
    }
    if(!zero && nve%2) ans+=2;
    else ans+=zero;
    cout << ans << "\n";
}

