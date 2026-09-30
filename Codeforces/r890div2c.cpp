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

ll t,n,k,a[1000],mx;
ll solve(){
    ll i,j,mid,res;
    res=i=0,j=1e10;
    while(i<=j){
        mid=(i+j)/2;
        ll cost,tmp,ok;
        for(int w=0;w<n;++w){
            ok=cost=0,tmp=mid;
            for(int q=w;q<n;++q){
                if(tmp-a[q]<=0){ok=1; break;}
                cost+=(tmp-a[q]),tmp--;
            }
            if(ok && cost<=k) break;
        }
        if(cost>k || !ok) j=mid-1;
        else {res=max(res,mid),i=mid+1;}
    }
    return res;
}
int main()
{
    fast_io;
    ll mx;
    cin>>t;
    while(t--&&cin>>n>>k){
        for(int q=0;q<n;++q)cin>>a[q];
        cout << solve() << "\n";
    }
}

/*
   author :tlx
               */









