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
const ll mdl=1e9+7;

ll t,n,k,res;
vector<ll> fac(200001);
int main()
{
    fast_io;
    auto inv=[](ll a){
        ll b=mdl-2,ans;
        ans=1;
        while(b){
            if(b&1) ans=(ans*a)%mdl;
            a=(a*a)%mdl;
            b>>=1;
        }
        return ans%mdl;
    };
    fac[0]=1LL;
    for(int q=1;q<200001;++q) fac[q]=q;
    partial_sum(fac.begin(),fac.end(),fac.begin(),[](ll a,ll b){return (a*b)%mdl;});
    cin>>t;
    ll i,m,z; 
    while(t--&&cin>>n>>k){
        m=z=0;
        ll arr[n]; for(auto&v:arr)cin>>v,m+=v,z+=v^1;
        i=ceil((double)k/2);
        //mCi * (n-i)C(k-i) 
        res=0;
        if(!z) res=(((fac[n]*inv(fac[n-k]))%mdl)*inv(fac[k]))%mdl;
        else{
            for(ll q=i;q<=k && q<=m;++q){
                //mCq * zCk-q /q!/(k-q)!
                if((k-q > z) || (q>m)) continue;
                res=res%mdl + ((((fac[m]*inv(fac[m-q]))%mdl*inv(fac[q]))%mdl) * (((fac[z]*inv(fac[z-k+q])%mdl)*inv(fac[k-q]))%mdl))%mdl;
            }
        }
        cout << res%mdl << "\n";
    }
}



