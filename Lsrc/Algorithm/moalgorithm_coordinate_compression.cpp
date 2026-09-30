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
 
 
constexpr ll mxN=2e5+1;
ll n,q,ans,mp[mxN]={0};
class Query{
    public:
    ll l,r,sz,idx;
    bool operator<(Query other)const{
        return make_pair(l/sz,this->r)<make_pair(other.l/other.sz,other.r);
    }
    Query(){}
};
void add(ll x,vc<ll> &a){mp[a[x]]++; ans+=(mp[a[x]]==1);}
void rm(ll x,vc<ll> &a){mp[a[x]]--; ans-=(!mp[a[x]]);}
void solve(istream &cin){
    cin>>n>>q;
    vc<Query> qu(q+1);
    vc<ll> a(n),res(q+1);
    for(auto&v:a) cin>>v;
    forn(i,1,q+1) cin>>qu[i].l>>qu[i].r,qu[i].l--,qu[i].r--,qu[i].sz=sqrt(n),qu[i].idx=i;
    sort(1+all(qu));
    vc<ll> d=a;
    sort(all(d));
    d.resize(unique(all(d))-d.bg());
    forn(i,0,n) a[i]=lwb(all(d),a[i])-d.bg(); //d[a[i]]
    ll l,r;
    ans=l=0,r=-1;
    forn(i,1,q+1){
        while(l>qu[i].l) add(--l,a);
        while(r<qu[i].r) add(++r,a);
        while(l<qu[i].l) rm(l++,a);
        while(r>qu[i].r) rm(r--,a);
        res[qu[i].idx]=ans;
    }
    forn(i,1,q+1) cout << res[i] << '\n';
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
