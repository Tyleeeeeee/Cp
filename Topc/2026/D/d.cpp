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
#define MAX(x,y) (x=max(x,y))
#define MIN(x,y) (x=min(x,y))
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=5e3+102;
ll n,a[mxN],b[mxN],c[mxN],d[mxN]{},vs[mxN],cnt[mxN]{};
vc<ar<ll,2>> adj[mxN];
bool spfa(){
	queue<ll> q;
	forn(i,0,n+1) q.emplace(i),vs[i]=1;
	while(!q.empty()){
		ll u=q.front(); q.pop(),vs[u]=0;
		for(auto &[v,w]:adj[u]){
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				if(!vs[v]){
					cnt[v]++,q.emplace(v),vs[v]=1;
					if(cnt[v]>=n) return false;
				}
			}
		}
	}
	return true;
}
void solve(){
	cin >> n;
	forn(i,1,n+1){
		cin >> a[i];
		if(i>1) adj[a[i-1]].emp(ar<ll,2>{a[i],0});
	}
	forn(i,1,n+1) cin >> b[i];
	forn(i,1,n+1) cin >> c[i];
	forn(i,1,n+1){
		if(i>1) adj[b[i]].emp(ar<ll,2>{b[i-1],c[b[i-1]]-c[b[i]]});
	}
	forn(i,1,n+1) adj[i].emp(ar<ll,2>{0,0}),adj[0].emp(ar<ll,2>{i,c[i]});
	cout << (spfa()?"Yes":"No") << '\n';
	//0>=x[a[i+1]-x[a[i]]; a[i]->a[i+1] w=0
	//c[b[i]]-x[b[i]]>=c[b[i+1]-x[b[i+1]]
	//c[b[i]]-c[b[i+1]]>=x[b[i]]-x[b[i+1]] b[i+1]->b[i] w=c[b[i]]-c[b[i+1]]
	//x[z]<=x[i]<=c[i]+x[z]
	//x[z]-x[i]<=0 i->z w=0
	//x[i]-x[z]<=c[i] z->i w=c[i]
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
