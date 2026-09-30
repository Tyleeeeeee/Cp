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

constexpr ll mxN=5e5+1;
int n,m;
vc<vc<pll>> h;
vc<int> adj[mxN],a(mxN),b(mxN),tin(mxN),tout(mxN);
void dfs(ll u,ll d,ll &T){
	if(d==h.size()) h.push_back({{0,0}});
	ll m; m=(--h[d].ed())->sc ^ (1<<(a[u]));
	h[d].emp(pll{T,m});
	tin[u]=T++;
	for(auto&v:adj[u]) dfs(v,d+1,T);
	tout[u]=T;
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,n){
		int x; cin>>x;
		adj[x-1].emp(i);
	}
	forn(i,0,n){
		char c; cin>>c;
		a[i]=c-'a';
	}
	ll tim; tim=1;
	dfs(0,0,tim);
	while(m--){
		int v,H; cin>>v>>H; v--,H--;
		// err(H,h.size());
		if(H>=h.size()){cout << "Yes" << '\n'; continue;}
		auto it1=lwb(all(h[H]),pll{tin[v],-1});
		auto it2=upb(all(h[H]),pll{tout[v],-1});
		// if(it1==h[d[v]+H-2].bg()){err("test1");}
		// if(it2==h[d[v]+H-2].bg()){err("test2");}
		it1--,it2--;
		// err(bitset<32>(it2->sc ^ it1->sc));
		cout << (bitset<32>(it2->sc ^ it1->sc).count()<=1?"Yes":"No") << '\n';
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
