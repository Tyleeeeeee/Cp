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
constexpr ll mxL=21;
constexpr ll mxN=1e5+10;
ll n,m;
string s,b;
ll dp[mxN][mxL];
ll comp(ll i,ll l){
	if(i-2*l+1>=1){
		forn(j,0,l) if(s[i-2*l+j]!=s[i-l+j]) return s[i-2*l+j]>s[i-l+j];
	}
	return 0;
}
ll f(ll l){
	if(n>=l){
		forn(j,0,l) if(s[n-l+j]!=b[j]) return s[n-l+j]<b[j];
	}
	return 1;
}
//654321 1000
//100100 100
void solve(){
	cin >> s >> b,n=s.length(),m=b.length();
	if(s=="0"){cout << 0 << '\n'; return;}
	memset(dp,0x3f,sizeof(dp));
	forn(l,1,mxL) dp[0][l]=0;
	ll lz;
	forn(i,1,n+1){
		forn(l,1,mxL){
			if(i-l<0) break;
			if(s[i-l]-'0') lz=0;
			else lz=1;
			if(!lz) dp[i][l]=dp[i-l][l-comp(i,l)]+1;
			//dp[i][l]=dp[i-l][l/l+1,mxL)+1
			//[i-2*l+1,i-l] vs [i-l+1,i]
			//if(i-2*l+1>=1
		}
		// err(i);
		// forn(l,1,mxL){ err(l,dp[i][l]);}
		if(i<n) forn(l,1,mxL) dp[i][l]=min(dp[i][l],dp[i][l-1]);
	}
	//dp[n-1][1,m-1/m]
	ll res=inf;
	// err(m,f(m));
	forn(l,1,m+f(m)) res=min(res,dp[n][l]);
	if(res<inf) cout << res-1 << '\n';
	else cout << "NO WAY\n" ;
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
