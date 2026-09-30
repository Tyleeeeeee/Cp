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

constexpr ll mxN=2e5+1;
ll n,q,t[mxN<<1],tim;
vc<ll> adj[mxN],va(mxN),tin(mxN),d(mxN),head(mxN),pa(mxN),dep(mxN);
void dfs(ll u=1,ll p=0){
	d[u]=1,pa[u]=p,dep[u]=dep[p]+1;
	for(auto&v:adj[u]){
		if(v==p || v==adj[u][0]) continue;
		dfs(v,u);
		d[u]+=d[v];
		if(adj[u][0]==u || d[v]>d[adj[u][0]]) adj[u][0]=v;
	}
}
void hld(ll u=1,ll p=1){
	tin[u]=++tim,t[tim+n-1]=va[u],head[u]=p;
	if(adj[u][0]!=u) hld(adj[u][0],p);
	for(auto&v:adj[u]){
		if(v==adj[u][0] || v==pa[u]) continue;
		hld(v,v);
	}
}
void built(){forr(i,n-1,1)t[i]=t[i<<1]+t[i<<1|1];}
void rst(ll p,ll val){for(t[p+=n-1]=val;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];}
ll query_(ll l,ll r){
	ll ans; ans=0;
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1) ans+=t[l++];
		if(!(r&1)) ans+=t[r--];
	}
	return ans;
}
ll query(ll l,ll r){
	ll ans; ans=0;
	// err(l,r);
	for(;head[l]!=head[r];r=pa[head[r]]){
		// err(l,r);
		if(dep[l]>dep[r]) swap(l,r);
		ans+=query_(tin[head[r]],tin[r]);
	}
	if(dep[l]>dep[r]) swap(l,r);
	return ans+=query_(tin[l],tin[r]);
}
void solve(istream &cin){
	cin>>n>>q;
	forn(i,1,n+1) cin>>va[i],adj[i].emp(i);
	forn(i,1,n){
		ll u,v; cin>>u>>v;
		adj[u].emp(v),adj[v].emp(u);
	}
	dep[0]=tim=0;
	dfs();
	hld();
	built();
	while(q--){
		ll op; cin>>op;
		if(op==1){
			ll s,x; cin>>s>>x;
			rst(tin[s],x);
		}
		else{
			ll s; cin>>s;
			cout << query(1,s) << '\n';
		}
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
