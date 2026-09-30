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

ll t,n,ok;
int main()
{
    fast_io;
    vector<ll> prime(32001,1),pri;
    prime[1]=0;
    for(int q=2;q<=32000;++q){
        if(prime[q]) {pri.pb(q); for(int w=q*q;w<=32000;w+=q) prime[w]=0;}
    }
    cin>>t;
    while(t-- && cin>>n){
        ll tmp;
        unordered_map<ll,ll> mp;
        ok=0;
        for(int q=0;q<n;++q){
            cin>>tmp;
            if(ok) continue;
            else{
                for(auto&p:pri){
                    if(!(tmp%p)) ok=(mp[p]>0?1:ok),mp[p]++;
                    while(!(tmp%p)) tmp/=p;
                }
            }
            if(tmp>1) ok=(mp[tmp]>0?1:ok),mp[tmp]++;
        }
        cout << (ok?"YES":"NO") << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/









