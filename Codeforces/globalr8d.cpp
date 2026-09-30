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

ll n,a[200001],b[200001],res;
int main()
{
    fast_io;
    cin>>n; 
    for(int q=0;q<n;++q) cin>>a[q];
    ll cnt;
    memset(b,0,sizeof(b));
    for(int q=0;q<21;++q){
        cnt=0;
        for(int w=0;w<n;++w){
            cnt+=((a[w] & (1<<q))!=0);
        }
        for(int w=0;w<cnt;++w) b[w]+=(1<<q);
    }
    for(int q=0;q<n;++q) res+=b[q]*b[q];
    cout << res << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



