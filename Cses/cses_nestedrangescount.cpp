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
 

constexpr ll mxN=2e5;
ll l[mxN+1]={0},r[mxN+1]={0};
void pad(ll *t,ll p,ll val){for(;p<=mxN;p+=p&-p)t[p]+=val;}
ll query(ll *t,ll p){if(!p) return 0; ll res; for(res=0;p;p-=p&-p)res+=t[p]; return res;}
void solve(istream &cin){
    ll n;
    cin>>n;
    vc<ll> b(n);
    vc<pr<ll,pll>> a(n);
    forn(i,0,n) cin>>a[i].fr>>a[i].sc.fr,a[i].sc.sc=i;
    sort(all(a),[](pr<ll,pll> c,pr<ll,pll> d){if(c.fr!=d.fr) return c.fr<d.fr; else return c.sc.fr>d.sc.fr;});
    forn(i,0,n) b[i]=a[i].sc.fr;
    vc<ll> d=b;
    sort(all(d));
    d.resize(unique(all(d))-d.bg());
    forn(i,0,n) b[i]=lwb(all(d),b[i])-d.bg()+1;
    ll pfx[mxN+1]={0},sfx[mxN+1]={0};
    forr(i,n-1,0) pad(sfx,b[i],1);
    forn(i,0,n){
        pad(sfx,b[i],-1);
        if(i){
            // b[i]
            r[a[i].sc.sc]=query(pfx,mxN)-query(pfx,b[i]-1);
        }
        // err(a[i].fr,a[i].sc.fr,a[i].sc.sc,b[i],query(sfx,b[i]));
        // err(a[i].fr,a[i].sc.fr,a[i].sc.sc,b[i],query(pfx,b[i]),query(pfx,mxN));
        l[a[i].sc.sc]=query(sfx,b[i]);
        pad(pfx,b[i],1);
    }
    forn(i,0,n) cout << l[i] << " \n"[i==n-1];
    forn(i,0,n) cout << r[i] << " \n"[i==n-1];
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
