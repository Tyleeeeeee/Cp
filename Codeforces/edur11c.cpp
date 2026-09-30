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

ll n,k,a[300001];
int main()
{
    fast_io;
    cin>>n>>k; for(int q=0;q<n;++q)cin>>a[q];
    ll lp,rp,li,ri,mxl,sum;
    mxl=sum=0,li=ri=-1;
    for(lp=rp=0;rp<n;++rp){
        sum+=a[rp]==0;
        while(sum>k){
            sum-=a[lp++]==0;
        }
        if(rp-lp+1>mxl) mxl=rp-lp+1,li=lp,ri=rp;
    }
    for(int q=li;q<=ri;++q) a[q]=1;
    cout << mxl << "\n";
    for(int q=0;q<n;++q) cout << a[q] << " ";
    cout << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



