#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll arr[n],res; for(auto&v:arr)cin>>v;
        vector<ll> ans;
        res=0;
        for(int q=0;q<min(32LL,n);++q){
            ll mx,mxi;
            mx=0,mxi=-1;
            for(int w=0;w<n;++w){
                if(arr[w]==-1) continue;
                if((res|arr[w]) > mx) mx=res|arr[w],mxi=w;
            }
            if(mxi!=-1) ans.push_back(arr[mxi]),res|=arr[mxi],arr[mxi]=-1;
        }
        for(auto&v:arr) if(v!=-1) ans.push_back(v);
        for(auto&v:ans) cout << v << " ";
        cout << "\n";
    }
}


