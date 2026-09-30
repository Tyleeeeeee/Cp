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

ll n,res,arr[100000];
map<ll,ll> mp;
int main()
{
    fast_io;
    cin>>n;
    res=0;
    for(ll q=0;q<n;++q){
        cin>>arr[q];
        if(mp.find(arr[q])!=mp.end()) mp[arr[q]]++;
        else mp[arr[q]]=1;
    }
    for(ll w=0;w<n;++w){//mp[(1<<q)-arr[w]]
        for(ll q=1;q<33;++q) if((1<<q)>arr[w]) res+=(mp.find((1<<q)-arr[w])==mp.end()?0:((1<<q)-arr[w]==arr[w])?mp[(1<<q)-arr[w]]-1:mp[(1<<q)-arr[w]]);
    }
    cout << res/2 << "\n";
}

