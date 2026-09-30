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

ll t,n,sm,ans;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){ 
        ans=sm=0;
        vector<pair<int,int>> solve;
        int arr[n]; for(auto&v:arr)cin>>v,sm+=v;
        if(sm&1) ans=-1;
        else{
            int lp,rp;
            for(lp=rp=0;rp<n;rp++){
                if(!arr[lp] && !arr[rp]) solve.push_back({lp+1,rp+1}),lp=rp+1;
                else {
                    if(arr[rp] && rp-lp>0){
                        if((rp-lp+1)&1){
                           if(arr[lp]*arr[rp]<0) solve.insert(solve.end(),{{lp+1,lp+1},{lp+2,rp},{rp+1,rp+1}});
                           else solve.insert(solve.end(),{{lp+1,lp+1},{lp+2,rp+1}});
                        }else{
                           if(arr[lp]*arr[rp]<0) solve.insert(solve.end(),{{lp+1,lp+1},{lp+2,rp+1}});
                           else solve.push_back({lp+1,rp+1});
                        }
                        lp=rp+1;
                    }
                }
            }
            ans=solve.size();
        }
        cout << ans << "\n";
        if(ans!=-1) for(auto&v:solve) cout << v.first << " " << v.second << "\n";
    }
}

