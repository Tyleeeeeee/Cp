#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int t,n;
    long long max;
    cin>>t;
    while(t--&&cin>>n){long long arr[n]; max=0;
        for(int q=0;q<n;++q){
            if(!q)cin>>arr[q];
            else cin>>arr[q],arr[q]+=arr[q-1];
        }
        for(int q=0;q<n;++q){
            if(arr[q]<0) max=max<arr[n-1]-arr[q]+abs(arr[q])?arr[n-1]-arr[q]+abs(arr[q]):max;
        }
        max=max<arr[n-1]?arr[n-1]:max;
        cout << max << "\n";
    }
}

