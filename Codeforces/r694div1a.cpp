#include<iostream>
#include<algorithm>
using namespace std;

int t,n,m,lp,rp;
int main()
{
    long long ans;
    cin>>t;
    while(t--&&cin>>n>>m){ long long arr[n],pr[m]; lp=ans=0,rp=m;
        for(auto&v:arr)cin>>v;
        for(auto&v:pr)cin>>v;
        sort(arr,arr+n,[](int a,int b){return a>b;});
        for(int q=0,tmp;q<n;++q){ 
            ans+=(arr[q]-1>=lp?pr[lp++]:pr[arr[q]-1]);
        }
        cout << ans << "\n";
    }
}


