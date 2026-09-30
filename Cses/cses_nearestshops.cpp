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
ll n,m,k,c[mxN]{},ans[mxN],vs[mxN]{};
vc<ll> adj[mxN];
pll res[mxN][2];
void solve(istream &cin){
	cin>>n>>m>>k;
	queue<ll> q2;
	queue<pll> q1;
	memset(res,0x3f,sizeof(res));
	forn(i,1,k+1){ll x; cin>>x,c[x]=1,res[x][0]={0,x},vs[x]=1,q1.emplace(pll{x,x});}
	forn(i,1,m+1){
		ll u,v; cin>>u>>v;
		adj[u].emp(v),adj[v].emp(u);
	}
	while(!q1.empty()){
		auto [u,fm]=q1.front(); q1.pop();
		for(auto&v:adj[u]){
			if(vs[v]){
				if(res[v][0].sc!=res[u][0].sc && res[v][1].fr>res[u][0].fr+1) res[v][1]={res[u][0].fr+1,res[u][0].sc},q2.emplace(v);
				continue;
			}
			res[v][0]={res[u][0].fr+1,fm},vs[v]=1,q1.emplace(pll{v,fm});
		}
	}
	memset(vs,0,sizeof(vs));
	{
		queue<ll> tmp=q2;
		while(!tmp.empty()){vs[tmp.front()]=1,tmp.pop();}
	}
	while(!q2.empty()){
		ll u=q2.front(); q2.pop();
		for(auto&v:adj[u]){
			if(vs[v]) continue;
			if(res[v][0].sc==res[u][0].sc) res[v][1]={res[u][1].fr+1,res[u][1].sc};
			else res[v][1]={res[u][0].fr+1,res[u][0].sc};
			vs[v]=1,q2.emplace(v);
		}
	}
	forn(i,1,n+1){
		if(!c[i]) ans[i]=(res[i][0].fr<INF?res[i][0].fr:-1);
		else ans[i]=(res[i][1].fr<INF?res[i][1].fr:-1);
	}
	forn(i,1,n+1) cout << ans[i] << " \n"[i==n];
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
