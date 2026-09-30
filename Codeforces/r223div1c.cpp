 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
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
#include<iterator>
#include<utility>
#include<cstdlib>
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
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
    template<typename T,typename... Args>
    inline void debug (const T& val,const Args&... args){
        cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
    }
    #define terr cerr << "I am here" << '\n'
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define ps push
#define emp emplace_back
#define pb push_back
#define lwb lower_bound
#define upb upper_bound
#define vc vector
#define ar array
#define uno unordered_map
#define uns unordered_set
#define pr pair
#define pll pr<ll,ll>
#define prq priority_queue
#define mls multiset
#define rbg rbegin
#define bg begin
#define ed end
#define fr first
#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
 
//0=L 1=D 2=R 3=U
// ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

class Node{
    public:
        ll l,r,res;
        Node(){}
        Node(ll L,ll R,ll Res):l(L),r(R),res(Res){}
        friend Node operator+(const Node &a,const Node &b){
            return {a.l+b.l-min(a.l,b.r),a.r+b.r-min(a.l,b.r),a.res+b.res+min(a.l,b.r)};
        }
};
constexpr ll mxN=2e6+1;
ll n,m;
Node t[mxN];
string s;
void built(){forr(i,n-1,1){t[i]=t[i<<1]+t[i<<1|1];}}
Node query(ll l,ll r){
    Node res1({0,0,0}),res2({0,0,0});
    for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
        // err(l,r);
        if(l&1) res1=res1+t[l++];
        if(!(r&1)) res2=t[r--]+res2;
    }
    return res1+res2;
}
void solve(istream &cin){
    cin>>s>>m;
    n=s.length();
    forn(i,0,n) t[i+n]={s[i]=='(',s[i]==')',0};
    built();
    while(m--){
        ll l,r; cin>>l>>r;
        cout << query(l,r).res*2 << '\n';
    }
}
int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

