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

ll n,m,k,l,r,ta[2][MAX5],pre[MAX5],mx;
pair<ll,ll> che[MAX5];
int main()
{
    fast_io;
    cin>>n>>m;
    for(int q=0;q<n;++q){
        mx=0;
        for(int w=0;w<m;++w){
            cin>>ta[q&1][w];
            if(q) pre[w]=(ta[q&1][w]>=ta[(q&1)^1][w]?pre[w]:0)+1;
            else pre[w]=1;
            mx=max(mx,pre[w]);
        }
        che[q].first=q,che[q].second=mx;
    }
    cin>>k;
    ll ok;
    while(k--&&cin>>l>>r){
        ok=(che[r-1].second<(r-l+1)?0:1);
        cout << (ok?"Yes":"No") << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



