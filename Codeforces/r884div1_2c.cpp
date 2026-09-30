#include<iostream>
using namespace std;

int main()
{
    int t,n,ct;
    long long ans1,ans2,max;
    cin>>t;
    while(t--&&cin>>n){ long long arr[n]; ct=ans1=ans2=0; max=-1e10;
        for(auto&v:arr)cin>>v,ct+=(v<0),max=(max<v?v:max);
        for(int q=0;q<n;++q){
            if(q%2) ans1+=(arr[q]>0?arr[q]:0);
            else ans2+=(arr[q]>0?arr[q]:0);
        }
        if(ct==n) cout << max << "\n";
        else cout << (ans1>ans2?ans1:ans2) << "\n";
    }
}

