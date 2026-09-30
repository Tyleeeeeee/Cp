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

ll t,n,a,b,res;
int main()
{
    fast_io;
    auto solve=[](ll a,ll c){
        ll ans;
        ans=1;
        while(c){
            if(c&1) ans=(ans*a)%b;
            a=(a*a)%b;
            c/=2;
        }
        return ans;
    };
    cin>>t;
    while(t--&&cin>>n>>a>>b){
        res=0;
        if(b==1) res=1;
        else if(a==1) res=(n%b==1);
        else{
            ll mdl,ok,cur;
            cur=1,mdl=ok=0;
            while((cur*=a)<=n) mdl++;
            for(int q=0;q<=mdl && !ok;++q) if(solve(a,q)%b == n%b) res=ok=1;
        }
        cout << (res?"YES":"NO") << "\n";
    }
}

