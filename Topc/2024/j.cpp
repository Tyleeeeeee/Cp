#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back

void solve(){
	string s;
	cin >> s;
	ll res=0;
	forn(i,0,s.length()){
		if(s[i]=='.'){cout << res << '\n'; return;}
		res=res*10+(s[i]-'0');
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
