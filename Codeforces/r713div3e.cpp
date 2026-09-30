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

int main()
{
    fast_io;
    ll t,n,l,r,s,ok;
    cin>>t;
    while(t--&&cin>>n>>l>>r>>s){
        ll x;
        unordered_set<ll> st;
        vector<ll> ans(n+1);
        ok=1,x=r-l+1; 
        for(int q=1;q<=n;++q) st.insert(q);
        if(s<(x*(x+1)/2) || s>(n*(n+1)/2-(n-x)*(n-x+1)/2)) ok=0;
        else{
            vector<ll> res(r-l+2);
            vector<ll> freq(n+1,0);
            for(int q=1;q<=r-l+1;++q) res[q]=n+q-x;
            s-=(n*(n+1)/2-(n-x)*(n-x+1)/2);
            for(int q=1;q<=r-l+1 && s;++q){
                while(res[q]!=q && s) res[q]--,s++;
            }
            for(int q=1;q<=r-l+1;++q) ans[l-1+q]=res[q],freq[res[q]]=1;
            ll ind=1;
            for(int q=1;q<=n;++q){
                if(l<=q && q<=r) continue;
                while(freq[ind]==1) ind++;
                ans[q]=ind,freq[ind]=1;
            }
        }
        if(ok) for(int q=1;q<=n;++q) cout << ans[q] << " \n"[q==n];
        else cout << -1 << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/











