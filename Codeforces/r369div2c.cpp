 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
#include<iostream>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<array>
#include<functional>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define DEBUG 1 
#if DEBUG
    #define debug(name,x) cerr << name << ':' << x << '\n' 
    #define debugr(name,i,n) for(ll I=i;I<n;++I) cerr << name[I] << " \n"[I==n-1] //i<= <n
    #define TEST cerr << "test" << "\n"
#else
    #define debug(x)
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=0x7FFFFFFFFFFFFFFF;
constexpr ll mx5=100001; //1e5+1
constexpr ll mx9=1000000001; //1e9+1
constexpr ll mx6=1000001; //1e6+1
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define ps push
#define emp emplace_back
#define pb push_back
#define vc vector
#define ar array
#define uno unordered_map
#define pr pair
#define prq priority_queue
#define mls multiset
#define bg begin
#define ed end
#define fr first
#define sc second
template<typename T> inline T gcd(T a,T b){if(!b) return a; while(a%=b) swap(a,b); return b;}
template<typename T> inline T lcm(T a,T b){return a*b/gcd(a,b);}
template<typename T> inline T add(T a,T b){return (a+b+mdl1)%mdl1;}
template<typename T> inline T add(T a,T b,T c){return ((a+b)%mdl1+c)%mdl1;}
template<typename T> inline T mul(T a,T b){return (a*b+mdl1)%mdl1;};
template<typename T> inline T mul(T a,T b,T c){return (((a*b)%mdl1)*c+mdl1)%mdl1;}
template<typename T> inline T bct(T a){return bitset<64>(a).count();}
template<typename T> inline T fsp(T a,T b){ll ans=1; while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}return ans;}
class gtr{public:bool operator()(ll a,ll b)const{return a>b;}};
class lss{public:bool operator()(ll a,ll b)const{return a<b;}};

int main()
{
    fast_io;
    ll n,m,k;
    cin>>n>>m>>k;
    vc<ll> c(n+1); for(int q=1;q<=n;++q) cin>>c[q];
    vc<vc<ll>> p(n+1,vc<ll>(m+1)); for(int q=1;q<=n;++q) for(int w=1;w<=m;++w) cin>>p[q][w];
    ll dp[n+1][k+1][m+1];
    for(int q=1;q<=m;++q) dp[1][1][q]=p[1][q];
    memset(dp,0x3f,sizeof(dp));
    for(int q=0;q<=m;++q) dp[0][0][q]=0;
    for(int w=1;w<=k;++w){
        for(int q=1;q<=n;++q){
            if(c[q]){
                dp[q][w][c[q]]=min(dp[q][w][c[q]],min(dp[q-1][w][c[q]],(q==1&&w==1?0:inf)));
                for(int co=1;co<=m;++co) if(co!=c[q]) dp[q][w][c[q]]=min(dp[q][w][c[q]],dp[q-1][w-1][co]);
            }
            else{
                for(int co=1;co<=m;++co){
                    dp[q][w][co]=min(dp[q][w][co],min(dp[q-1][w][co]+p[q][co],(q==1&&w==1?p[q][co]:inf)));
                    for(int a=1;a<=m;++a) if(a!=co) dp[q][w][co]=min(dp[q][w][co],dp[q-1][w-1][a]+p[q][co]);
                }
            }
        }
    }
    ll res=inf;
    for(int q=1;q<=m;++q) res=min(res,dp[n][k][q]);
    cout << (res>=0x3f3f3f3f3f3f3f3f?-1:res) << "\n";
    return 0;
}

