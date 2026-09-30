#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,ans,counter;
    long long x;
    cin>>t;
    while(t--&&cin>>n>>x){long long arr[n]; ans=0,counter=1;
        for(auto&v:arr)cin>>v;
        sort(arr,arr+n,[](int a,int b){return a>b;});
        for(int q=0;q<n;++q){
            if(arr[q]*counter>=x){ans++,counter=1;}
            else counter++;
        }
        cout << ans << "\n";
    }
}

