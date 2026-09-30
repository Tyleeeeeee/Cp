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
using i128=__int128;

//10010103 200
//1001003 100
//1000100 100
//10001000 100
constexpr ll inf=0x3f3f3f3f3f3f3f3f;

void solve(){
	ll n,pt,pu,rt,ru,f;
	string s;
	cin >> n;
	vc<ar<ll,2>> a;
	forn(i,1,7){
		cin >> s >> pt >> pu >> rt >> ru >> f;
		a.emp(ar<ll,2>{56*ru+24*rt+14*pu+6*pt+30*f,s=="Taiwan"});
	}
	sort(all(a),[](auto x,auto y){return x[0]>y[0];});
	ll i;
	for(i=1;i<7;i++) if(a[i-1][1]) break;
	ll res=n/6+(n%6 >= i);
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
