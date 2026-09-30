#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
using ll=unsigned long long;
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

void solve(){
	ll n,k,ld;
	cin >> n >> k;
	ll ls=(k>63 ? n : min(n,(1ull<<k)-1)),l=0,r=ls,m;
	ld=64-__builtin_clzll(n);
	while(r-l>1){
		m=l+r>>1;
		ll lv=64-__builtin_clzll(m),L=m<<(ld-lv),R=L+(1ull<<ld-lv)-1,s=(1ull<<ld-lv+1)-1; //ld max=63 lv min=1
		if(n<R){
			if(n<L) s-=1ull<<ld-lv;
			else s-=R-n;
		}
		//k<=n-s+1
		if(k<=n-s+1) r=m;
		else l=m;
	}
	cout << (ls-r+1) << '\n';
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
