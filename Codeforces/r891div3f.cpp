#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,q,x,y;
map<ll,ll> mp;
ll solve(){
    ll ans;
    //(a1^2+a2^2-2a1a2+4a1a2)=(x^2) (a1-a2)^2+4y=x^2 (a1-a2)=x^2-4y a1-a2=sqrt(x^2-4y) a1=(sqrt(x^2-4y)+x)/2;
    ans=(sqrt(x*x-4*y)+x)/2;
    if(ans*(x-ans)!=y) ans=0;
    else if(ans==(x-ans)) ans=mp[ans]*(mp[ans]-1)/2; // mp[ans]C2
    else ans=mp[ans]*mp[x-ans];
    return ans;
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll tmp;
        mp.clear();
        for(int i=0;i<n;++i)cin>>tmp,mp[tmp]++;
        cin>>q;
        for(int i=0;i<q;++i){
            cin>>x>>y;
            cout << solve() << " ";
        }
        cout << "\n";
    }
}
/*
   author :tlx
               */

