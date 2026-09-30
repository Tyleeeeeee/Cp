#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long ;

int main()
{
    ll t,n,x;
    cin>>t;
    while(t--&&cin>>n>>x){
        int arr[n];
        for(auto&v:arr)cin>>v;
        ll mxl[n+1],sm;
        for(int q=0;q<n+1;++q) mxl[q]=-0x16161616;
        for(int q=0;q<n;++q){
            sm=0;
            for(int w=q;w<n;++w){
                sm+=arr[w];
                mxl[w-q+1]=max(mxl[w-q+1],sm);
            }
        }
        ll ans;
        for(int k=0;k<=n;++k){ ans=0;
            for(int l=1;l<=n;++l){
                ans=max(ans,mxl[l]+min(k,l)*x);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}

