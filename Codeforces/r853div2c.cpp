#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int lg[400001];
int main()
{
    fast_io;
    ll t,n,m;
    cin>>t;
    while(t--&&cin>>n>>m){
        ll arr[n],pos[n],mx;
        mx=0;
        memset(lg,0,sizeof(lg)),memset(pos,0,sizeof(pos));
        ll tmp;
        for(int q=0;q<n;++q){
            cin>>arr[q],mx=max(mx,arr[q]);
        }
        ll p,v;
        for(int q=1;q<=m+1;++q){
            if(q<m+1){
                cin>>p>>v,mx=max(mx,v);
                lg[arr[p-1]]+=q-pos[p-1],arr[p-1]=v,pos[p-1]=q;
            }
            else for(int q=0;q<n;++q) if(pos[q]<=m) lg[arr[q]]+=m-pos[q]+1;
        }
        ll sum=m*(m+1)/2,ans=0;
        for(int q=1;q<=mx;++q){
            if(!lg[q]) continue;
            ans+=sum-((m+1-lg[q])>1)*((m+1-lg[q])*(m-lg[q]))/2;
        }
        cout << ans << "\n";
    }
}

