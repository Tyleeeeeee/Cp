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

constexpr ll mxX=2e5+1;
constexpr ll mxN=5e5+1;
ll n,q,sz,res,cnt[mxN]{},mp[mxN]{},a[mxX],b[mxX]{};
ll dfs(ll open,vc<ll> &f,ll i,ll x,ll y){
	if(i==f.size()){
		ll tmp; tmp=(y?cnt[x]-open:0),cnt[x]+=open?-1:1;
		return y&1?tmp:-tmp;
	}
	return dfs(open,f,i+1,x?x*f[i]:f[i],y+1)+dfs(open,f,i+1,x,y);
}
void solve(istream &cin){
	cin>>n>>q;
	forn(i,1,n+1) cin>>a[i];
	res=sz=0;
	while(q--){
		ll x,y; cin>>x;
		vc<ll> f;
		y=a[x];
		while(y>1){
			ll p; p=mp[y];
			f.emp(p);
			while(y%p==0) y/=p;
		}
		ll z; z=dfs(b[x],f,0,0,0);
		res+=(b[x]?-1:1)*(sz-b[x]-z),sz+=(b[x]?-1:1),b[x]^=1;
		cout << res << '\n';
	}
}
 
int main()
{
	forn(i,2,mxN){
		if(!mp[i]){
			mp[i]=i;
			for(ll j=i*i;j<mxN;j+=i) mp[j]=i;
		}
	}
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
