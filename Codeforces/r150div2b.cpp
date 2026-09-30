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

ll n,ans;
ll ok(ll a){set<ll> st; while(a){st.insert(a%10),a/=10;} return st.size()>2?0:1;}
void dfs(ll a){
    if(a>0 && a<=n) ans++;
    if(a>=MAX9 || a>n) return ;
    for(int q=0;q<10;++q){
        if(a*10+q && ok(a*10+q)) dfs(a*10+q);
    }
}
int main()
{
    fast_io;
    cin>>n;
    ans=0;
    dfs(0);
    cout << ans << "\n";
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/



