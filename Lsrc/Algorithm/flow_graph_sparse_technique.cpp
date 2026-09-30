 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
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
#define fast_io cin.tie(0),ios_base::sync_with_stdio(false)
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
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
// char dir[4]={'L','D','R','U'};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=505;
class Node{
	public:
		ll u,v,c,f;
		Node(){}
		Node(ll u,ll v,ll c):u(u),v(v),c(c){f=0;}
};
ll n,en,n0,n1,a[mxN][mxN],id=0;
vc<ll> adj[mxN*mxN+2*mxN],ptr,pa;
vc<Node> edg;
bool bfs(){
	queue<ll> q;
	q.emplace(pa[0]=0);
	while(q.size()){
		ll x=q.front(); q.pop();
		for(auto&id:adj[x]){
			auto [u,v,c,f]=edg[id];
			if(pa[v]==-1 && c-f>0) pa[v]=pa[u]+1,q.emplace(v);
		}
	}
	return pa[en]!=-1;
}
ll dfs(ll u=0,ll flow=inf){
	if(!flow) return 0;
	if(u==en) return flow;
	for(ll &cid=ptr[u];cid<adj[u].size();++cid){
		ll d=adj[u][cid],tr=0;
		auto [x,y,c,f]=edg[d];
		if(pa[y]==pa[x]+1 && c-f>0) tr=dfs(y,min(flow,c-f));
		if(!tr) continue;
		edg[d].f+=tr,edg[d^1].f-=tr;
		return tr;
	}
	return 0;
}

void solve(){
	cin >> n;
	en=n*n+2*n+1,n0=n1=0;
	ptr.resize(en+1),pa.resize(en+1);
	forn(i,0,n){
		forn(j,0,n){
			cin >> a[i][j],a[i][j]--;
			if(a[i][j]>0){
				edg.emp(Node{0,i*n+j+1,a[i][j]}),edg.emp(Node{i*n+j+1,0,0}),adj[0].emp(id++),adj[i*n+j+1].emp(id++);
				edg.emp(Node{i*n+j+1,n*n+i+1,a[i][j]}),edg.emp(Node{n*n+i+1,i*n+j+1,0}),adj[i*n+j+1].emp(id++),adj[n*n+i+1].emp(id++);
				edg.emp(Node{i*n+j+1,n*n+n+j+1,a[i][j]}),edg.emp(Node{n*n+n+j+1,i*n+j+1,0}),adj[i*n+j+1].emp(id++),adj[n*n+n+j+1].emp(id++);
			}
			else if(a[i][j]<0){
				edg.emp(Node{i*n+j+1,en,1}),edg.emp(Node{en,i*n+j+1,0}),adj[i*n+j+1].emp(id++),adj[en].emp(id++);
				edg.emp(Node{n*n+i+1,i*n+j+1,1}),edg.emp(Node{i*n+j+1,n*n+i+1,0}),adj[n*n+i+1].emp(id++),adj[i*n+j+1].emp(id++);
				edg.emp(Node{n*n+n+j+1,i*n+j+1,1}),edg.emp(Node{i*n+j+1,n*n+n+j+1,0}),adj[n*n+n+j+1].emp(id++),adj[i*n+j+1].emp(id++);
			}
			n0+=a[i][j]>=0;
		}
	}
	//0 = s //n^2+1 sink
	for(;;){
		fill(all(ptr),0),fill(all(pa),-1);
		if(!bfs()) break;
		for(ll nf;nf=dfs();n1+=nf);
	}
	cout << (n*n-n0-n1)*2+n1 << '\n';
}
int main()
{
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
