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
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ii=int;
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
#define pii pr<ii,ii>
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
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mX=1e9;
constexpr ll mxN=1e5+1;
vc<ll> pa(mxN,-1),rl(mxN,0);
ll find(ll x){return pa[x]<0?x:find(pa[x]);}
void un(ll x,ll y,ll val){
    x=find(x),y=find(y);
    if(x==y) {rl[x]+=val; return;}
    if(-pa[x]>-pa[y]) swap(x,y);
    pa[y]+=pa[x],pa[x]=y,rl[y]+=rl[x]+val;
}
void solve(istream &cin){
    ll n,m,p,q;
    vc<ar<ll,2>> res;
    cin>>n>>m>>p>>q;
    forn(i,1,m+1){
        ll l,x,y; cin>>x>>y>>l;
        un(x,y,l);
    }
    ll region,x,y; region=0;
    forn(i,1,n+1) region+=(pa[i]<0);
    x=region-q,y=p-x;
    if((q==n && p>0) || region<q || x>p){cout << "NO" << '\n'; return;}
    mls<ar<ll,2>> hp;
    forn(i,1,n+1) if(pa[i]<0) hp.emplace(ar<ll,2>{rl[i],i});
    while(x--){
        auto it1=*hp.bg(); hp.erase(hp.bg());
        auto it2=*hp.bg(); hp.erase(hp.bg());
        un(it1[1],it2[1],min(mX,it1[0]+it2[0]+1));
        res.emp(ar<ll,2>{it1[1],it2[1]}),hp.emplace(ar<ll,2>{it1[0]+it2[0]+min(mX,it1[0]+it2[0]+1),find(it1[1])});
    }
    if(y){
        ll ta; ta=-1;
        forn(i,1,n+1) if(pa[i]<-1){ta=i; break;}
        forn(i,1,n+1) if(i!=ta && find(i)==ta){while(y--) res.emp(ar<ll,2>{i,ta}); break;}
    }
    cout << "YES" << '\n';
    for(auto&v:res) cout << v[0] << ' ' << v[1] << '\n';
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
