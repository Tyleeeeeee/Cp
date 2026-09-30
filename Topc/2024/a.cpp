#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)

constexpr ll mxN=1e5+1;
ll v[mxN];
string s[mxN];
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll mx=0,res=0;
	forn(i,1,n+1) {cin >> s[i] >> v[i]; if(s[i]=="pig") mx=max(mx,v[i]);}
	forn(i,1,n+1) if(s[i]!="pig" && v[i]<mx) res+=v[i];
	cout << (res+mx) << '\n';
	return 0;
}
