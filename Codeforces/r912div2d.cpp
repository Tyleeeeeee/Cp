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
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX5 100001 //1e5+1
#define MAX9 1000000001 //1e9+1
#define MAX6 1000001 //1e6+1
#define pb(x) push_back(x)

ll n,t,k,a[MAX5],b[MAX5],res,up;
void solve(){
    ll cost,ok;
    for(int w=62;w>=0;--w){
        ok=1,cost=0;
        for(int q=0;q<n && ok;++q){
            if(!(a[q]&(1LL<<w)))cost+=(a[q]&(1LL<<w)?0:(1LL<<w)-(((1LL<<w)-1)&a[q])),ok=cost>k?0:1;
        }
        if(cost<=k) {
            res+=(1LL<<w),k-=cost;
            for(int q=0;q<n;++q){
                if(!(a[q]&(1LL<<w))) a[q]&=~((1LL<<w)-1);
            }
        }
    }
    cout << res << "\n";
}
int main()
{
    fast_io;
    cin>>n>>t;
    for(int q=0;q<n;++q)cin>>b[q];
    while(t--&&cin>>k){
        res=0;
        for(int q=0;q<n;++q) a[q]=b[q];
        solve();
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



