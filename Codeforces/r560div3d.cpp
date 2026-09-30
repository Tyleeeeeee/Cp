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

ll t,n,d[300],res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        ll ok;
        map<ll,ll> mp;
        for(int q=0;q<n;++q) cin>>d[q],mp[d[q]]++;
        sort(d,d+n);
        ok=1,res=(n&1?d[n/2]*d[n/2]:d[0]*d[n-1]);
        for(ll q=2;q*q<=res && ok;++q){
            ok=((!(res%q) && mp.find(q)==mp.end())||(!(res%q) && (res/q!=q) && mp.find(res/q)==mp.end()))?0:ok;
        }
        for(ll q=0;q<n && ok;++q){
            if(res%d[q]) ok=0;
        }
        res=(ok?res:-1);
        cout << res << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



