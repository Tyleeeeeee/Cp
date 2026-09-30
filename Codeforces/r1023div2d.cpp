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
ll n,ver;
vc<ll> adj[mxN],vs(mxN),d(mxN),ord;
vc<ar<ll,3>> res;
void dfs(ll v,ll p){
	d[v]=d[p]+1;
	if(!ver || d[ver]<d[v] || (d[ver]==d[v] && v>ver)) ver=v;
	for(auto&to:adj[v]){
		if(to==p || vs[to]) continue;
		dfs(to,v);
	}
}
bool utov(ll v,ll p,ll f){
	if(v==f){
		ord.emp(v);
		return true;
	}
	for(auto&to:adj[v]){
		if(to==p || vs[to]) continue;
		if(utov(to,v,f)){
			ord.emp(v);
			return true;
		}
	}
	return false;
}
void solve(ll v){
	ver=0;
	dfs(v,0);
	v=ver,ver=0;
	dfs(v,0);
	ll u=ver;// u<->v
	if(u<v) swap(u,v);
	res.emp(ar<ll,3>{max(d[u],d[v]),u,v});
	ord.clear();
	utov(u,0,v);
	// cerr << "\n----\n";
	// for(auto&V:path) cout << V << ' '; cout << '\n';
	// cerr << "\n----\n";
	auto daun=ord;
	for(auto&x:daun) vs[x]=1;
	for(auto&x:daun){
		for(auto&k:adj[x]){
			if(!vs[k]) solve(k);
		}
	}
}
void solve(istream &cin){
	cin>>n;
	res.clear(),ord.clear();
	forn(i,1,n+1) adj[i].clear(),vs[i]=d[i]=0;
	forn(i,1,n){
		ll u,v; cin>>u>>v;
		adj[u].emp(v),adj[v].emp(u);
	}
	solve(1);
	sort(all(res),[](auto a,auto b){return a>b;});
	for(auto&[d,u,v]:res) cout << d << ' ' << u << ' ' << v << ' '; cout << '\n';
}
 
int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
