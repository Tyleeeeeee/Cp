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
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
#else
    #define debug(x)
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll MAX5=100001; //1e5+1
constexpr ll MAX9=1000000001; //1e9+1
constexpr ll MAX6=1000001; //1e6+1
#define all(name) name.begin(),name.end()
#define pb(x) push_back(x)
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

int main()
{
    fast_io;
    string s;
    vector<ll> a(1<<2,0);
    cin>>s;
    //0=1 1=6 2=8 3=9
    for(char &c:s){
        if(c=='1' && !a[0]) c='0',a[0]^=1;
        else if(c=='6' && !a[1]) c='0',a[1]^=1;
        else if(c=='8' && !a[2]) c='0',a[2]^=1;
        else if(c=='9' && !a[3]) c='0',a[3]^=1;
    }
    sort(all(s),[](char a,char b){return a>b;});
    s.erase(s.length()-4,4);
    ll ok,rm;
    ok=rm=0;
    for(char &c:s) rm=(rm*10+(c-'0'))%7,ok=(c-'0'?1:ok);
    for(int q=0;q<4;++q) rm=(rm*10)%7;
    if(rm==1) s+="1896";
    else if(rm==2) s+="9861";
    else if(rm==3) s+="1698";
    else if(rm==4) s+="6198";
    else if(rm==5) s+="1689";
    else if(rm==6) s+="6189";
    else{
        if(ok) s+="9618";
        else s="9618"+s;
    }
    cout << s << "\n";
    return 0; 
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/

