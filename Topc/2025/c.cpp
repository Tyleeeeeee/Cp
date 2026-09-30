#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)

constexpr ll mxN=2e5+1;
ll x[mxN],y[mxN],dp[mxN],v[mxN];
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	while(testcase--){
		ll n,m; cin >> n >> m;
		ll x[m],y[m],v[m],dp[n+1],res=0;
		memset(dp,0,8*(n+1));
		forn(i,1,m+1) cin >> x[i] >> y[i] >> v[i];
		forr(i,m,1){
			ll p=dp[y[i]]+v[i],q=dp[x[i]]+v[i];
			res=max({res,dp[x[i]]=p,dp[y[i]]=q});
		}
		cout << res << '\n';
	}
	return 0;
}
