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
    ll t,a,b,x,ok;
    cin>>t;
    while(t--&&cin>>a>>b>>x){
        if(x>max(a,b)) ok=0;
        else{
            ok=0;
            if(a>b) swap(a,b);
            while(!ok){
                if(x%a==b%a) ok=1;
                ll y=b/a;
                b-=y*a;
                swap(a,b);
                if(!a || b<x){
                    if(b==x) ok=1;
                    else break;
                }
            }
        }
        cout << (ok?"YES":"NO") << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/









