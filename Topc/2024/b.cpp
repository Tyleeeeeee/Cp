#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)

constexpr ll inf=1e18;
constexpr ll mxN=3e5+1;
ll n,a[mxN];
void solve(){
	cin >> n;
	ll res=0;
	a[0]=0;
	forn(i,1,n+1) cin >> a[i],res+=abs(a[i]),a[i]+=a[i-1];
	// cerr << "init: " << res << '\n';
	for(ll sfx=0,pfx=res,mx=-inf,i=n;i>0;i--){
		pfx-=abs(a[i]-a[i-1]);
		mx=max(mx,2*a[i]+sfx);
		res=max(res,mx-2*a[i-1]+pfx);
		// cerr << "i: " << i << ' ' << res << '\n';
		// cerr << "pfx: " << pfx << " mx: " << mx << '\n';
		sfx+=abs(a[i]-a[i-1]);
	}
	//i j 2*pfx[j]+sfx[j+1]-2*pfx[i-1] b[j]=2*pfx[j]+sfx[j+1]
	cout << res << '\n';
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
