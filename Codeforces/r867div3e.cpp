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
    ll t,n,a[26],mx,res;
    string s;
    cin>>t;
    while(t--&&cin>>n>>s){
        mx=0;
        memset(a,0,sizeof(a));
        for(char &c:s) a[c-'a']++,mx=max(a[c-'a'],mx);
        if((n&1) || (mx>n/2)) res=-1;
        else{
            mx=res=0;
            memset(a,0,sizeof(a));
            for(int q=0;q<s.length()/2;++q) if(s[q]==s[s.length()-q-1]) res++,a[s[q]-'a']++,mx=max(mx,a[s[q]-'a']);
            res=max((res/2)+(res&1),mx);
        }
        cout << res << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/







