#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back

constexpr ll mxN=18;
ll n,b[mxN],dp[1<<mxN][101]{};
vc<ll> res;
void dfs(ll mask,ll c){
	cout << c << ' ';
	if(!mask){exit(0);}
	forn(j,0,18){
		if( (mask>>j&1)  && b[j]%c==0 && b[j]/c<=100 && dp[mask^1<<j][b[j]/c]) dfs(mask^1<<j,b[j]/c);
	}
}
void solve(){
	cin >> n;
	forn(i,0,n-1) cin >> b[i];
	forn(c,1,101) dp[0][c]=1;
	forn(i,1,(1<<(n-1))){
		forn(c,1,101){
			forn(j,0,mxN) if( (i>>j&1) && b[j]%c==0 && b[j]/c<101) dp[i][c]|=dp[i^1<<j][b[j]/c];
		}
	}
	forn(c,1,101){
		if(dp[(1<<(n-1))-1][c]){
			cout << "Yes" << '\n';
			dfs((1<<(n-1))-1,c);
		}
	}
	cout << "No" << '\n';
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
