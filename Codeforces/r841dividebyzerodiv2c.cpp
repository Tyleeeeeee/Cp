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

ll t,n,a[200001],res;
vector<ll> sq={0};
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll sum;
        vector<ll> pref(2*n,0);
        pref[0]=1,sum=res=0;
        for(int q=0;q<n;++q){
            cin>>a[q],sum^=a[q];
            for(int w=0;w*w<2*n;++w) if((sum^(w*w))<2*n) res+=pref[sum^(w*w)];
            pref[sum]++;
        }
        res= n*(n+1)/2-res;
        cout << res << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/





