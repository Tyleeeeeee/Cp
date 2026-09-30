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
#pragma GCC optimize("O3")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=5e4+5;
ll n,m,Q,in[mxN]{},dfn[mxN]{},low[mxN],cs[mxN],st[mxN],vs[mxN]{},sz=0,scc=0,tim=0;
bitset<mxN> a[mxN];
vc<ll> adj[mxN],t[mxN];
void tarjan(ll u){
	dfn[u]=low[u]=++tim,st[++sz]=u,vs[u]=1;
	for(auto&v:adj[u]){
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vs[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++scc;
		while(st[sz]^u) vs[st[sz]]=0,cs[st[sz--]]=scc; vs[u]=0,cs[u]=scc,sz--;
	}
}
void solve(istream &cin){
	cin>>n>>m>>Q;
	forn(i,1,n+1) a[i][i]=1;
	forn(i,1,m+1){ll u,v; cin>>u>>v; adj[u].emp(v);}
	forn(i,1,n+1) if(!dfn[i]) tarjan(i);
	forn(i,1,n+1) for(auto&v:adj[i]) if(cs[v]!=cs[i]) t[cs[v]].emp(cs[i]),in[cs[i]]++;
	queue<ll> q;
	forn(i,1,scc+1) if(!in[i]) q.emplace(i);
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(auto&v:t[u]){
			in[v]--,a[v]|=a[u]; if(!in[v]) q.emplace(v);
		}
	}
	while(Q--){
		ll u,v; cin>>u>>v;
		cout << (cs[u]==cs[v] || a[cs[u]][cs[v]]?"YES":"NO") << '\n';
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
