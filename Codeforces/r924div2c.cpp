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

int main()
{
    fast_io;
    ll t,n,x;
    cin>>t;
    while(t--&&cin>>n>>x){
        unordered_set<ll> st;
        if(!((n&1)^(x&1))){
            ll y1,y2;
            y1=(n+x-2)/2,y2=(n-x)/2;
            for(ll q=1;q*q<=y1;++q){
                if(!(y1%q)){
                    if(q+1>=x) st.insert(q+1);
                    if(y1/q!=q && y1/q+1>=x) st.insert(y1/q+1);
                }
            }
            for(ll q=1;q*q<=y2;++q){
                if(!(y2%q)){
                    if(q+1>=x) st.insert(q+1);
                    if(y2/q!=q && y2/q+1>=x) st.insert(y2/q+1);
                }
            }
        }
        cout << st.size() << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







