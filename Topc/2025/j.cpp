#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ar array
#define vc vector
#define emp emplace_back
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)


constexpr ll mxN=5e5+1;
	
ll n,k,gk,l=0,r=2e14,m;
vc<ar<ll,2>> adj[mxN];
ll dfs(ll u=1,ll p=0){
	ll d1=0,d2=0;
	//cerr << u << ' ' << p << '\n';
	for(auto &[v,l]:adj[u]){
		if(v!=p){
			ll x=dfs(v,u);
			if(~x) x+=l;
			else return -1;
			if(x>m){
				if(gk) gk--,x=l;
				else return -1;
			}
			if(x>d2) d2=x;
			if(d2>d1) swap(d2,d1);
		}
	}
	if(d1+d2>m){
		if(gk) gk--,d1=0;
		else return -1;
	}
	return d1;
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin >> n >> k;
	forn(i,1,n){ll u,v,w; cin >> u >> v >> w; adj[u].emp(ar<ll,2>{v,w}),adj[v].emp(ar<ll,2>{u,w}),l=max(l,w);}
	l--;
	while(r-l>1){
		m=l+r>>1,gk=k;
		//cerr << "m: " << m  << ' ' << l << ' ' << r << '\n';
		if(~dfs()) r=m;
		else l=m;
	}
	cout << r << '\n';
	return 0;
}
