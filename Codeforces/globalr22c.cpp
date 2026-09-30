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

ll t,n,a,b,ans;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll od,evn,tmp;
        od=evn=0;
        for(int q=0;q<n;++q) cin>>tmp,od+=tmp&1;
        evn=n-od;
        ll i,j;
        i=ceil((double)od/2),j=floor((double)od/2);
        if(!od || n==1) ans=od^1;
        else if(od==1) ans=(evn&1?1:0);
        else if(od==2) ans=0;
        else if(i&1) ans=(evn&1 && (j&1)^1?1:0);
        else ans=1;
        cout << (ans?"Alice":"Bob") << "\n";
    }
}

