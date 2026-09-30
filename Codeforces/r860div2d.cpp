#include<iostream>
#include<bitset>
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
#include<unordered_map>
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
#define is(x) insert(x)
#define log2(x) (log(x)/log(2))

ll t,n,mx,mn;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll ok;
        mn=inf,mx=0;
        vector<ll> a(n),ans; for(auto&v:a)cin>>v,mx=max(mx,v),mn=min(mn,v);
        sort(a.begin(),a.end());
        if(mx>=mx-mn) ok=0;
        else{
            ll sum,lp,rp,ind;
            ok=1,lp=sum=0,ind=lower_bound(a.begin(),a.end(),0)-a.begin(),rp=ind;
            for(;ans.size()<n;){
                if(rp<n && !a[rp]) ans.pb(a[rp++]);
                else if((sum<=0 && rp<n) || lp==ind) ans.pb(a[rp]),sum+=a[rp++];
                else if(lp<ind)ans.pb(a[lp]),sum+=a[lp++];
            }
        }
        cout << (ok?"Yes":"No") << "\n";
        if(ok) for(int q=0;q<n;++q) cout << ans[q] << " \n"[q==n-1];
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







