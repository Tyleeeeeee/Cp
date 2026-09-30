#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
const ll mx=1e9;

ll t,p,q,res;
map<ll,ll> mp;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>p>>q){
        mp.clear();
        ll tmp=q;
        while(tmp%2==0) {
            if(mp.find(2)==mp.end()) mp[2]=1;
            else mp[2]++;
            tmp/=2;}
        for(ll w=3;w<=sqrt(tmp);w+=2){
            while(tmp%w==0){
                if(mp.find(w)==mp.end()) mp[w]=1;
                else mp[w]++;
                tmp/=w;
            } 
        }
        if(tmp>2) mp[tmp]=1;
        res=0;
        if(p%q) res=p;
        else{
            for(auto&v:mp){
                tmp=p;
                while(tmp%q==0) tmp/=v.first;
                res=max(res,tmp);
            }
        }
        cout << res << "\n";
    }
}

