#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
using ll = long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define vc vector
#define pr pair
#define fr first
#define sc second
#define pll pr<ll,ll>
#define emp emplace_back
#define mls multiset
#define bg begin
    
class DSU{
    private:
        ll n;
        vc<ll> arr;
        vc<ll> rank;

    public:
        DSU(){}
        DSU(ll N):n(N),arr(N+1),rank(N+1,1){
            forn(i,0,N+1) arr[i]=i;
        }
        ll find(ll p){
            if(arr[p]!=p){
                arr[p]=find(arr[p]);
            }
            return arr[p];
        }
        void un(ll p,ll q){
            if(p==q) return;
            if(rank[p]>rank[q]){
                arr[q]=p;
            }
            else if(rank[p]<rank[q]){
                arr[p]=q;
            }
            else{
                arr[p]=q;
                rank[q]++;
            }
        }
};
constexpr ll mxN=1e5+1;
ll n,m,res;
vc<ll> adj[mxN];
mls<pr<ll,pll>> edg;
void kruskal(){
    ll cnt;
    DSU dsu(n);
    cnt=0;
    while(cnt<n-1){
        ll x,y,z;
        auto top=*edg.bg();
        z=top.fr,x=top.sc.fr,y=top.sc.sc;
        edg.erase(edg.bg());
        if(dsu.find(x)^dsu.find(y)){
            dsu.un(x,y);
            res+=z;
            adj[x].emp(y),adj[y].emp(x);
        }
        cnt++;
    }
}
int main()
{
    cin>>n>>m;
    forn(i,1,m+1){
        ll x,y,z;
        cin>>x>>y>>z;
        edg.emplace(pr<ll,pll>{z,{x,y}});
    }
    kruskal();
    cout << res << '\n';
}

