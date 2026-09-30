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

constexpr ll mxN=2e5+1;
ll t[mxN]{},n;
ll query(ll p){ll ans=0; for(;p;ans+=t[p],p-=p&-p); return ans;}
void pad(ll p,ll val){for(;p<=n;t[p]+=val,p+=p&-p);}
void solve(){
	cin >> n;
	ll res=0;
	forn(i,1,n+1){
		ll x; cin >> x;
		res+=i-1-query(x);
		pad(x,1);
	}
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
