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

ll t,n,res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll tmp,pre,sum;
        sum=res=pre=0;
        for(int q=0;q<n;++q){
            cin>>tmp;
            if(q && tmp<pre) {
                ll ttmp;
                ttmp=tmp;
                while(ttmp<pre) ttmp<<=1,sum++;
            }
            else if(q && tmp>=pre && sum){
                ll ttmp;
                ttmp=pre;
                while(sum && tmp>=(ttmp<<1)) ttmp<<=1,sum--;
            }
            pre=tmp;
            res+=sum;
        }
        cout << res << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







