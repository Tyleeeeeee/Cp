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
	ll n;
	cin >> n;
	string s[n];
	vc<ar<ll,4>> a(n);
	forn(i,0,n){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		getline(cin,s[i]),a[i][3]=i,s[i]=s[i].substr(1);
	}
	sort(all(a),[](auto x,auto y){return x[0]>y[0]||(x[0]==y[0] && x[1]>y[1])||(x[0]==y[0] && x[1]==y[1] && x[2]>y[2]);});
	cout << s[a[0][3]] << '\n';
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
