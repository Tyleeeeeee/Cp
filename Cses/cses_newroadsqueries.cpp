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
#include<complex>
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
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
//#pragma GCC optimize ("03")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=2e5+1;
ll n,m,q,lo[mxN],hi[mxN],pa[mxN];
vc<ll> b[mxN];
vc<ar<ll,2>> adj,Q;
ll find(ll x){return pa[x]<0?x:pa[x]=find(pa[x]);}
void un(ll x,ll y){
	x=find(x),y=find(y); if(x==y) return;
	if(-pa[x]>-pa[y]) swap(x,y); pa[y]+=pa[x],pa[x]=y;
}
void solve(istream &cin){
	cin>>n>>m>>q;
	forn(i,0,m){ll u,v; cin>>u>>v,u--,v--; adj.emp(ar<ll,2>{u,v});}
	forn(i,0,q){ll u,v; cin>>u>>v,u--,v--; Q.emp(ar<ll,2>{u,v});}
	fill(lo,lo+q,0),fill(hi,hi+q,m-1);
	for(ll ok=1;ok;){
		ok=0;
		forn(i,0,q) if(lo[i]<=hi[i]) ok|=1,b[(lo[i]+hi[i])>>1].emp(i);
		fill(pa,pa+n,-1);
		forn(i,0,m){
			auto &[u,v]=adj[i]; un(u,v);
			for(auto &id:b[i]){
				auto &[x,y]=Q[id];
				if(find(x)==find(y)) hi[id]=i-1;
				else lo[id]=i+1;
			}
			b[i].clear();
		}
	}
	forn(i,0,q) cout << (Q[i][0]==Q[i][1]?0:lo[i]>m-1?-1:lo[i]+1) << '\n';
}
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
