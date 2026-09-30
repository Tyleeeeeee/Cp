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
#pragma GCC optimize ("03")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
// char dir[4]={'L','D','R','U'};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=2e5+1;
ll n,m,q,res[mxN],id=0,pa[mxN];
ar<ll,4> st[mxN];
vc<ll> s[mxN],r[mxN];
vc<ar<ll,3>> edg,wg[mxN];
ll find(ll x){return pa[x]<0?x:pa[x]=find(pa[x]);}
ll un(ll x,ll y){
	x=find(x),y=find(y); if(x==y) return 0;
	if(-pa[x]>-pa[y]) swap(x,y);
	st[++id]=ar<ll,4>{x,pa[x],y,pa[y]};
	pa[y]+=pa[x],pa[x]=y;
	return 1;
}
void roll(ll x){
	while(id>x){
		auto [u,U,v,V]=st[id--];
		pa[u]=U,pa[v]=V;
	}
}
void sol(){
	forn(i,0,mxN){
		if(wg[i].empty()) continue;
		for(auto&ind:r[i]){
			ll ID=id;
			//err(ID);
			for(ll j=s[ind].size()-1;j>=0;j--){
				auto &[w,u,v]=edg[s[ind][j]];
				if(w>i) break;
				res[ind]&=(find(u)!=find(v));
				un(u,v);
			}
			//err(ID,id);
			roll(ID);
			//err(ID,id);
			//err(i,ind,res[ind]);
			for(;s[ind].size() && edg[s[ind].back()][0]==i;s[ind].pop_back());
			if(res[ind] && s[ind].size()) r[edg[s[ind].back()][0]].emp(ind);
		}
		for(auto&[w,u,v]:wg[i]) un(u,v);
		//err(i,id);
	}
}
void solve(){
	cin >> n >> m >> q;
	vc<ll> a(m);
	forn(i,0,m){
		ll u,v,w;
		cin >> u >> v >> w;
		a[i]=w,edg.emp(ar<ll,3>{w,u,v});
	}
	memset(pa,-1,sizeof(pa));
	sort(all(a)),a.resize(unique(all(a))-a.bg());
	for(auto &[w,u,v]:edg){
		w=lwb(all(a),w)-a.bg();
		wg[w].emp(ar<ll,3>{w,u,v});
	}
	forn(i,0,q){
		ll k; cin >> k;
		forn(j,0,k){
			ll tmp; cin >> tmp,tmp--;
			s[i].emp(tmp);
		}
		sort(all(s[i]),[](ll a,ll b){return edg[a][0]>edg[b][0];});
		r[edg[s[i].back()][0]].emp(i);
		res[i]=1;
	}
	sol();
	forn(i,0,q) cout << (res[i]?"YES":"NO") << '\n';
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

