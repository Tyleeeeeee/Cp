#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define DEBUG 1
   #if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
       template<typename T,typename... Args>
       inline void debug (const T& val,const Args&... args){
           cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
       }
       #define terr cerr << "I am here" << '\n'
   #endif
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back
#define all(x) x.begin(),x.end()
using ull=unsigned long long;
using u128=unsigned __int128;
using i128=__int128;

ull a, b, m, A, T2;
ar<ull,2> dfs(ull k){
	if(k == 0) return {T2, A};
	auto [x, y] = dfs(k >> 1);
	ull xx = (ull)(((u128)x * x + m - T2) % m);
	ull xy = (ull)(((u128)x * y + m - A ) % m);
	ull yy = (ull)(((u128)y * y + m - T2) % m);
	return (k & 1) ? ar<ull,2>{xy, yy} : ar<ull,2>{xx, xy};
}

void solve(){
	cin >> a >> b >> m;
	A = a % m;
	T2 = 2 % m;
	cout << dfs(b)[0] << '\n';
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
