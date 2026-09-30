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
 
class Query{
	public:
		ll l,r,ind,k,sz;
		Query(){}
		Query(ll L,ll R,ll i,ll K,ll SZ):l(L),r(R),ind(i),k(K),sz(SZ){}
		friend bool operator<(const Query &a,const Query &b){
			if(a.l/a.sz !=b.l/b.sz) return a.l/a.sz<b.l/b.sz;
			return a.r<b.r;
		}
};
constexpr ll mxN=1e5+1;
ll n,m,c[mxN],tim,cl,ans,t[mxN]={0};
vc<ll> adj[mxN],tin(mxN),tout(mxN),res(mxN),cnt(mxN,0);
void dfs(ll u=1,ll p=0){
	tin[u]=++tim;
	for(auto&v:adj[u]){
		if(v==p)
			continue;
		dfs(v,u);
	}
	tout[u]=tim;
}
void add(ll p,ll val){if(p<=0) return; for(;p<mxN;p+=p&-p) t[p]+=val;}
ll query(ll p){if(p<=0) return 0; ll ans; ans=0; for(;p;p-=p&-p) ans+=t[p]; return ans;}
ll query(ll l,ll r){return l>r?0:query(r)-query(l-1);}
void solve(istream &cin){
	cin>>n>>m;
	vc<ll> a(n+1);
	vc<Query> q;
	forn(i,1,n+1) cin>>c[i];
	forn(i,1,n){
		ll u,v; cin>>u>>v;
		adj[u].emp(v),adj[v].emp(u);
	}
	tim=0,dfs();
	// forn(i,1,n+1){err(i,tin[i]);}
	forn(i,1,n+1) a[tin[i]]=c[i];
	// forn(i,1,n+1){err(i,a[i]);}
	forn(i,1,m+1){
		ll v,k; cin>>v>>k;
		q.emp(Query{tin[v],tout[v],i,k,(ll)sqrt(n)});
		//tin[v]-tout[v]
	}
	sort(all(q));
	ll l,r; l=1,r=0;
	for(auto&[L,R,ind,k,sz]:q){
		while(l<L) add(cnt[a[l]],-1),cnt[a[l]]--,add(cnt[a[l]],1),l++;
		while(l>L) add(cnt[a[l-1]],-1),cnt[a[l-1]]++,add(cnt[a[l-1]],+1),l--;
		while(r>R) add(cnt[a[r]],-1),cnt[a[r]]--,add(cnt[a[r]],+1),r--;
		while(r<R) add(cnt[a[r+1]],-1),cnt[a[r+1]]++,add(cnt[a[r+1]],+1),r++;
		res[ind]=query(k,mxN-1);
	}
	forn(i,1,m+1) cout << res[i] << '\n';
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
