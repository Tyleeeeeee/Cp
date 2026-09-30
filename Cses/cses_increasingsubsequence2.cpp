#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define lwb lower_bound
#define upb upper_bound
#define bg begin
#define ed end
#define all(x) x.bg(),x.ed()
#define vc vector
 
constexpr ll mod=1e9+7;
constexpr ll mxN=2e5+1;
ll n,t[mxN]={0},dp[mxN]={0};
vc<ll> a,b;
void pad(ll p,ll val){for(;p<mxN;p+=p&-p)t[p]=(t[p]+val)%mod;}
ll query(ll p){if(p<=0) return 0; ll ans; ans=0; for(;p>0;p-=p&-p)ans=(ans+t[p])%mod; return ans;}
ll query(ll l,ll r){
	return (l>r?0:query(r)-query(l-1));
}
void solve(istream&cin){
	cin>>n;
	a.resize(n);
	for(auto&v:a) cin>>v;
	b=a,sort(all(b)),b.resize(unique(all(b))-b.bg());
	for(auto&v:a) v=(lwb(all(b),v)-b.bg())+1;
	//forn(i,0,n) cerr << "i:" << ' ' << a[i] << '\n';
	forn(i,0,n){
		//cerr << "i: " << i << ' ' << "a[i]: " << a[i] << ' ' << query(1,a[i]-1) << '\n';
		ll v; v=dp[a[i]];
		dp[a[i]]=(dp[a[i]]+query(1,a[i]-1)+1)%mod;
		//forn(j,1,11) cerr << dp[j] << " \n"[j==10];
		pad(a[i],dp[a[i]]-v);
	}
	ll res; res=0;
	forn(i,1,mxN){
		res=(res+dp[i])%mod;
	}
	cout << res << '\n';
}
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	//ifstream cin("input.txt");
	solve(cin);
	return 0;
}
