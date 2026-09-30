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
 
constexpr ll mxN=1e5+1;
ll n,m,tim,pa[mxN],f[mxN],ett[mxN]{},rett[mxN],id[mxN],sd[mxN],label[mxN];
vc<ll> adj[mxN],radj[mxN],t[mxN],res;
void dfs(ll u=1){
	ett[u]=++tim,rett[ett[u]]=u;
	label[tim]=id[tim]=sd[tim]=tim;
	for(auto&v:adj[u]){
		if(!ett[v]){
			dfs(v);
			f[ett[v]]=ett[u];
		}
		radj[ett[v]].emp(ett[u]);
	}
}
ll find(ll u,ll x=0){
	if(pa[u]<0) return x?-1:u;
	ll v=find(pa[u],x+1);
	if(v<0) return u;
	if(sd[label[u]]>sd[label[pa[u]]]) label[u]=label[pa[u]];
	pa[u]=v;
	return x?v:label[u];
}
void built(){
	vc<ll> arr[n+1];
	forr(i,n,1){
		for(auto&v:radj[i]){
			sd[i]=min(sd[i],sd[find(v)]);
		}
		if(i>1) arr[sd[i]].emp(i);
		for(auto&v:arr[i]){
			ll x=find(v);
			if(sd[x]==sd[v]) id[v]=sd[v];
			else id[v]=x;
		}
		if(i>1) pa[i]=f[i];
	}
	forn(i,2,n+1){if(id[i]!=sd[i]) id[i]=id[id[i]]; t[rett[i]].emp(rett[id[i]]),t[rett[id[i]]].emp(rett[i]);}
}
void dfs_ans(ll u=1,ll p=0){
	res.emp(u);
	if(u==n){
		sort(all(res));
		cout << res.size() << '\n';
		for(auto&v:res) cout << v << ' '; cout << '\n';
		exit(0);
	}
	for(auto&v:t[u]){
		if(v==p)
			continue;
		dfs_ans(v,u);
	}
	res.pop_back();
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,m+1){
		ll u,v; cin>>u>>v;
		adj[u].emp(v);
	}
	tim=0;
	memset(pa,-1,sizeof(pa));
	dfs();
	built();
	dfs_ans();
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
