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

ll n,m,k,x,s,res,a[200001],b[200001],c[200001],d[200001];
ll bns(ll tar){
    ll i,j,mid;
    i=0,j=k-1;
    while(i<=j){
        mid=(i+j)/2;
        if(d[mid]<=tar) i=mid+1;
        else j=mid-1;
    }
    return (j!=-1?c[j]:0);
}
int main()
{
    fast_io;
    cin>>n>>m>>k>>x>>s;
    for(int q=0;q<m;++q)cin>>a[q];
    for(int q=0;q<m;++q)cin>>b[q];
    for(int q=0;q<k;++q)cin>>c[q];
    for(int q=0;q<k;++q)cin>>d[q];
    res=(n-bns(s))*x;
    for(int q=0;q<m;++q){
        if(b[q]<=s) res=min(res,(n-bns(s-b[q]))*a[q]);
    }
    cout << res << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



