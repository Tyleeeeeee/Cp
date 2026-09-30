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

ll n,k,num[100001];
int main()
{
    fast_io;
    cin>>n>>k;
    ll arr[n],res,lp,rp,i,j; for(auto&v:arr)cin>>v;
    i=-1,j=-1;
    memset(num,0,sizeof(num));
    for(res=lp=rp=0;rp<n;++rp){
        if(!num[arr[rp]]) res++;
        num[arr[rp]]++;
        while(res==k){
            i=lp+1,j=rp+1;
            num[arr[lp]]--;
            if(!num[arr[lp++]]) res--;
        }
    }
    cout << i << " " << j << "\n";
}


