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

ll t,n,k,a[200001];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>k){
        ll lb,up,ok;
        for(int q=0;q<n;++q) cin>>a[q];
        lb=up=a[0]+k,ok=1;
        for(int q=1;q<n && ok;++q){
            ll x,y;
            x=(q<n-1?a[q]+2*k-1:a[q]+k),y=a[q]+k;
            lb=max(lb-k+1,a[q]+k),up=min(up+k-1,a[q]+2*k-1);
            if(x<lb || y>up || lb>up) ok=0;
        }
        cout << (ok?"YES":"NO") << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



