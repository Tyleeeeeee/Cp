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
    ll t,x,y;
    cin>>t;
    while(t--&&cin>>x>>y){
        cout << (x>y?(x+y):y-(y%x)/2) << "\n";
    }
    return 0;
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/









