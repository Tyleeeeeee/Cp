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
 
constexpr ll mxN=26;
ll n,cnt[mxN],vs[mxN];
string s;
vc<ll> adj[mxN];
void solve(){
	cin >> n >> s;
	forn(i,0,mxN) adj[i].clear();
	memset(cnt,0,sizeof(cnt));
	memset(vs,0,sizeof(vs));
	forn(i,0,n) cnt[s[i]-'a']++,adj[s[i]-'a'].emp(i);
	vc<ar<ll,2>> tmp;
	forn(i,0,mxN) if(cnt[i]) tmp.emp(ar<ll,2>{cnt[i],i});
	sort(all(tmp));
	ar<ll,2> mn={inf,-1};
	forn(i,1,mxN+1){
		if(n%i) continue;
		ll cost=0,d=n/i;
		forr(j,tmp.size()-1,max(0LL,(ll)tmp.size()-i)) cost+=max(0LL,tmp[j][0]-d);
		if(tmp.size()>i) forn(j,0,tmp.size()-i) cost+=tmp[j][0];
		if(cost<mn[0]) mn={cost,i};
	}

	ll d=n/mn[1];
	vc<ll> store;
	forr(j,tmp.size()-1,max(0LL,(ll)tmp.size()-mn[1])){
		ll c=tmp[j][1];
		while(adj[c].size()>d) store.emp(adj[c].back()),adj[c].pop_back();
	}
	if(tmp.size()>mn[1]){
		forn(j,0,tmp.size()-mn[1]) {
			ll c=tmp[j][1];
			while(adj[c].size()) store.emp(adj[c].back()),adj[c].pop_back();
		}
	}
	forr(j,tmp.size()-1,max(0LL,(ll)tmp.size()-mn[1])){
			ll c=tmp[j][1];
			while(adj[c].size()<d) adj[c].emp(store.back()),store.pop_back();
	}
	if(mn[1]>tmp.size()){
		ll x=mn[1]-tmp.size();
		for(auto &[fq,c]:tmp) vs[c]=1;
		forn(i,0,mxN){
			if(!x) break;
			if(vs[i]) continue;
			while(adj[i].size()<d) adj[i].emp(store.back()),store.pop_back();
			x--;
		}
	}
	forn(i,0,mxN) for(auto &v:adj[i]) s[v]=(char)(i+'a');
	cout << mn[0] << '\n' << s << '\n';
}
int main()
{
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
