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
 
constexpr ll mxN=1e5+1;
ll n,m,k,res,d[mxN];
mls<ar<ll,2>> hp;
vc<ar<ll,2>> adj[mxN];
void djk(){
	d[1]=0,hp.emplace(ar<ll,2>{d[1],1});
	while(!hp.empty()){
		auto [dist,u]=*hp.bg(); hp.erase(hp.bg());
		if(u<=n && dist>d[u]) continue;
		if(u>n){
			u-=n;
			if(dist>=d[u]){
				res++;
				continue;
			}
			d[u]=dist;
		}
		for(auto&[v,w]:adj[u]){
			if(d[u]+w<d[v]) d[v]=d[u]+w,hp.emplace(ar<ll,2>{d[v],v});
		}
	}
}
void solve(istream &cin){
	cin>>n>>m>>k;
	forn(i,1,m+1){
		ll u,v,w; cin>>u>>v>>w;
		adj[u].emp(ar<ll,2>{v,w}),adj[v].emp(ar<ll,2>{u,w});
	}
	forn(i,1,k+1){
		ll u,w; cin>>u>>w;
		hp.emplace(ar<ll,2>{w,u+n});
	}
	res=0;
	memset(d,0x3f,sizeof(d));
	djk();
	cout << res << '\n';
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
