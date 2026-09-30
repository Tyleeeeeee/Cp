#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector

constexpr ll mxN=5e5+1;
ll n,d[mxN]{},res[mxN]{},t[mxN]{};
vc<ar<ll,2>> c(mxN);
ll query(ll p){ll ans=0; for(;p;ans+=t[p],p-=p&-p); return ans;}
void pad(ll p,ll val){for(;p<=n;t[p]+=val,p+=p&-p);}
void solve(){
	cin >> n;
	forn(i,1,n+1) cin >> c[i][0];
	forn(i,1,n+1) cin >> c[i][1];
	sort(1+c.bg(),c.bg()+n+1);
	ll ok=0;
	forn(i,1,n+1) cerr << c[i][0] << " \n"[i==n];
	forn(i,1,n+1) cerr << c[i][1] << " \n"[i==n];
	forn(i,1,n+1){
		ok+=(d[c[i][1]]=i-1-query(c[i][1]));
		pad(c[i][1],1);
	}
	cout << (ok&1?"No":"Yes") << endl;
	if(ok&1^1){
		ok>>=1;
		ll t=1;
		for(;;t++){
			if(d[t]>=ok) break;
			else ok-=d[t];
		}
		//t -> t+d[t]-ok
		//1 2 3 .. t-1 x x .. . t x x x x
		res[t+d[t]-ok]=t;
		forn(i,1,t) res[i]=i;
		for(ll p=1,i=1;p<=n && i<=n;i++){
			if(c[i][1]<=t) continue;
			while(p<=n && res[p]) p++;
			res[p]=c[i][1];
		}
		sort(1+c.bg(),c.bg()+n+1,[](auto x,auto y){return x[1]<y[1];});
		forn(i,1,n+1) cout << c[res[i]][0] << " \n"[i==n];
		forn(i,1,n+1) cout << res[i] << " \n"[i==n];
	}
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
