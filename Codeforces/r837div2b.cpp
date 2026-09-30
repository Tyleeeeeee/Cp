#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
using ll=long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll t,n,m;
    cin>>t;
    while(t--&&cin>>n>>m){
        ll x,y,arr[n+1];
        for(int q=1;q<=n;++q) arr[q]=n;
        while(m--&&cin>>x>>y){
            if(x>y) swap(x,y);
            arr[x]=min(arr[x],y-1);
        }
        for(int q=n-1;q>0;--q){
            arr[q]=min(arr[q],arr[q+1]);
        }
        ll ans=n;
        for(int q=1;q<=n;++q) ans+=arr[q]-q;
        cout << ans << "\n";
    }
}

