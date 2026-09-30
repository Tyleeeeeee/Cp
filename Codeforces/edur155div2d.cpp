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

ll n,res;
int main()
{
    fast_io;
    cin>>n;
    vector<ll> a(n); for(auto&v:a)cin>>v;
    res=0;
    for(int q=0;q<30;++q){
        ll cnt1,cnt0,sum1,sum0,pref;
        sum1=sum0=cnt1=cnt0=pref=0;
        for(int w=0;w<n;++w){
            if(pref)
                sum1+=w,cnt1++;
            else 
                sum0+=w,cnt0++;
            pref^=(a[w]&(1<<q));
            if(pref)
                res=(res+(((cnt0*(w+1)-sum0)%mdl2)*(1LL<<q)%mdl2))%mdl2;
            else
                res=(res+(((cnt1*(w+1)-sum1)%mdl2)*(1LL<<q)%mdl2))%mdl2;
        }
    }
    cout << res << "\n";
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







