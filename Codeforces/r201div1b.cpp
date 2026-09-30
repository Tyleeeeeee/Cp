 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<iostream>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
#include<complex>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<array>
#include<functional>
#include<iterator>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ii=int;
using ll=long long;
using ull=unsigned long long;
#define DEBUG 1 
#if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
    template<typename T,typename... Args>
    inline void debug (const T& val,const Args&... args){
        cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
    }
    #define terr cerr << "I am here" << '\n'
#endif
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define all(name) name.begin(),name.end()
#define allb(name) name.begin(),name.begin()
#define ps push
#define emp emplace_back
#define pb push_back
#define lwb lower_bound
#define upb upper_bound
#define vc vector
#define ar array
#define uno unordered_map
#define uns unordered_set
#define pr pair
#define pii pr<ii,ii>
#define pll pr<ll,ll>
#define prq priority_queue
#define mls multiset
#define rbg rbegin
#define bg begin
#define ed end
#define fr first
#define sc second
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("03")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=105;
ll n,m,q,dp[mxN][mxN][mxN],nxt[mxN][26],pa[mxN][mxN][mxN];
string s1,s2,v;
vc<ll> Kmp(){
	vc<ll> kmp(q,0);
	forn(i,1,q){
		ll j=kmp[i-1];
		while(j>0 && v[i]!=v[j]) j=kmp[j-1];
		if(v[i]==v[j]) kmp[i]=j+1;
	}
	return kmp;
}
void solve(istream &cin){
	cin>>s1>>s2>>v;
	n=s1.length(),m=s2.length(),q=v.length();
	vc<ll> kmp=Kmp();
	forn(i,0,q){
		forn(j,0,26){
			if(i>0 && (v[i]-'A')!=j) nxt[i][j]=nxt[kmp[i-1]][j];
			else nxt[i][j]=i+(v[i]-'A'==j);
		}
	}
	memset(dp,0,sizeof(dp));
	forn(i,1,n+1){
		forn(j,1,m+1){
			vc<ll> st(q);
			if(s1[i-1]==s2[j-1]){
				forn(k,0,q) st[k]=dp[i-1][j-1][k];
				forn(k,0,q) if(ll x=nxt[k][s1[i-1]-'A']; x!=q) if(dp[i-1][j-1][k]+1>st[x])st[x]=dp[i-1][j-1][k]+1,pa[i][j][x]=k;
			}
			else{
				forn(k,0,q) st[k]=max(dp[i-1][j][k],dp[i][j-1][k]);
			}
			forn(k,0,q) dp[i][j][k]=st[k];
		}
	}
	string res;
	ll i=n,j=m,k,ans=0; forn(i,0,q) if(dp[n][m][i]>ans) ans=dp[n][m][i],k=i;
	while(ans){
		if(dp[i-1][j][k]==ans) i--;
		else if(dp[i][j-1][k]==ans) j--;
		else{
			res+=s1[i-1],k=pa[i][j][k],i--,j--,ans--;
		}
	}
	reverse(all(res));
	if(res.length()) cout << res << '\n';
	else cout << 0 << '\n';
}
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

