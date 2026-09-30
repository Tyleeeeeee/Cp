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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=2e5+1;
ll n,m,q,res[mxN]{},pa[mxN],st[mxN],sz,cntm[mxN]{},cnt[mxN]{};
vc<ar<ll,3>> adj[mxN];
vc<ar<ll,4>> edg;
ll find(ll x){return pa[x]<0?x:pa[x]=find(pa[x]);}
void un(ll x,ll y){
	x=find(x),y=find(y); if(x==y) return;
	if(-pa[x]>-pa[y]) swap(x,y); pa[y]+=pa[x],pa[x]=y;
}
void solve(){
	memset(pa,-1,sizeof(pa));
	forn(i,0,m){
		if(adj[i].empty()) continue;
		for(auto&[u,v,ind]:adj[i]) res[ind]=(find(u)!=find(v));
		for(auto&[u,v,ind]:adj[i]) un(u,v);
	}
}
void kruskal(){
	memset(pa,-1,sizeof(pa));
	ll c=0;
	for(ll i=0;i<m && c<n-1;++i){
		if(adj[i].empty()) continue;
		for(auto&[u,v,ind]:adj[i]){
			if(find(u)!=find(v)) un(u,v),cntm[i]++,c++;
		}
	}
}
void solve(istream &cin){
	cin>>n>>m>>q;
	vc<ll> a;
	forn(i,1,m+1){
		ll u,v,w; cin>>u>>v>>w;
		a.emp(w),edg.emp(ar<ll,4>{w,u,v,i});
	}
	sort(all(a)),a.resize(unique(all(a))-a.bg());
	for(auto&[w,u,v,i]:edg) adj[w=(lwb(all(a),w)-a.bg())].emp(ar<ll,3>{u,v,i});
	solve();
	kruskal();
	memset(pa,-1,sizeof(pa));
	while(q--){
		ll k,ok; cin>>k;
		ok=1,sz=0;
		forn(i,1,k+1){
			ll ind; cin>>st[++sz];
			ok&=res[st[sz]];
			auto [w,u,v,inx]=edg[st[sz]-1];
			if(find(u)==find(v)) ok=0;
			else{
				cnt[w]++;
				if(cnt[w]>cntm[w]) ok=0;
				un(u,v);
			}
		}
		while(sz){
			auto [w,u,v,ind]=edg[st[sz--]-1];
			pa[u]=pa[v]=-1,cnt[w]=0;
		}
		cout << (ok?"YES":"NO") << '\n';
	}
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
