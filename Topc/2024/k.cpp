#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back

constexpr ll mxN=1e5+1;
ll n,m,in[mxN]{};
vc<ll> adj[mxN],res;
void solve(){
	cin >> n >> m;
	forn(i,1,m+1){ll u,v; cin >> u >> v,in[v]++,adj[u].emp(v);}
	multiset<ll> hp;
	forn(i,1,n+1) if(!in[i]) hp.emplace(i);
	while(hp.size()){
		auto u=*hp.bg(); hp.erase(hp.bg());
		res.emp(u);
		for(auto &v:adj[u]){
			in[v]--;
			if(!in[v]) hp.emplace(v);
		}
	}
	if(res.size()<n){cout << "IMPOSSIBLE" << '\n'; return;}
	forn(i,0,n) cout << res[i] << " \n"[i==n-1];
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	int testcase;
	testcase=1;
	//cin >> testcase;
	while(testcase--) solve();
	return 0;
}
