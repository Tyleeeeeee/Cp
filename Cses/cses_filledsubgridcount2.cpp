#include<iostream>
#include<cstdio>
#include<bitset>
#include<fstream>
#include<iomanip>
#include<vector>
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
constexpr ll finv=(mdl1+1)/2;
constexpr ll inf=1e18;
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=3e3+5;
ll n,k,res[26],dp[mxN],h[mxN],st[mxN];
// char s[mxN][mxN];
char grid[mxN*mxN];
 
char buf[mxN * mxN + mxN+100];
int pos = 0;
 
inline void fastReadInput() {
    int len = fread(buf, 1, sizeof(buf), stdin);
    buf[len] = '\0';
 
    while (buf[pos] < '0' || buf[pos] > '9') ++pos;
    while (isdigit(buf[pos])) n = n * 10 + (buf[pos++] - '0');
    while (buf[pos] < '0' || buf[pos] > '9') ++pos;
    while (isdigit(buf[pos])) k = k * 10 + (buf[pos++] - '0');
 
    for (int i = 1; i <= n; ++i) {
        while (buf[pos] < 'A' || buf[pos] > 'Z') ++pos;
        for (int j = 1; j <= n; ++j)
            grid[(i-1)*n+j] = buf[pos++];
    }
}
ll count(ll L,ll R){
	ll ans,sz;
	sz=ans=0;
	forr(i,R,L){
	 	while(sz>0 && h[i]<=h[st[sz]]) sz--;
		if(sz>0) dp[i]=(st[sz]-i)*h[i]+dp[st[sz]];
		else dp[i]=(R+1-i)*h[i];
		st[++sz]=i;
		ans+=dp[i];
	}
	return ans;
}
void solve(){
	// cin>>n>>k;
	// scanf("%lld%lld",&n,&k);
	memset(res,0,sizeof(res));
	fastReadInput();
	forn(i,1,n+1){
		forn(j,1,n+1){
			if(i>1 && grid[(i-1)*n+j]==grid[(i-2)*n+j]) h[j]++;
			else h[j]=1;
		}
		for(ll j=1;j<n+1;){
			char ch; ch=grid[(i-1)*n+j];
			ll L,R; L=j;
			while(j<n+1 && grid[(i-1)*n+j]==ch) j++;
			R=j-1;
			res[ch-'A']+=count(L,R);
		}
	}
	forn(i,0,k) printf("%lld\n",res[i]);
}
 
int main()
{
    // fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
