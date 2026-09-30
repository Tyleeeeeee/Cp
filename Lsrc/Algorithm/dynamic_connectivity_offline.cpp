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
#pragma GCC optimize("O3")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=1e5+5;
ll n,m,k,pa[mxN],ans[mxN],cc,sz=0;
ar<ll,4> st[mxN<<1];
vc<ar<ll,2>> t[mxN<<2];
map<ar<ll,2>,ll> mp;
ll find(ll x){return pa[x]<0?x:find(pa[x]);}
ll un(ll x,ll y){
	x=find(x),y=find(y); if(x==y) return 0;
	if(-pa[x]>-pa[y]) swap(x,y); st[++sz]={x,pa[x],y,pa[y]},pa[y]+=pa[x],pa[x]=y,cc--;
	return 1;
}
void roll(){
	auto [u,U,v,V]=st[sz--];
	pa[u]=U,pa[v]=V,cc++;
}
void upd(ar<ll,2> &query,ll l,ll r,ll i,ll sl,ll sr){
	if(sl>r || sr<l) return;
	if(l<=sl && sr<=r){t[i].emp(query);return;}
	ll mid=(sl+sr)>>1;
	upd(query,l,r,i<<1,sl,mid),upd(query,l,r,i<<1|1,mid+1,sr);
}
void dfs(ll i,ll sl,ll sr){
	ll su=0;
	for(auto&[u,v]:t[i]){su+=un(u,v);}
	if(sl==sr) ans[sl]=cc;
	else{
		ll mid=(sl+sr)>>1;
		dfs(i<<1,sl,mid);
		dfs(i<<1|1,mid+1,sr);
	}
	while(su--) roll();
}
void solve(istream &cin){
	cin>>n>>m>>k;
	forn(i,1,m+1){ll u,v; cin>>u>>v; if(u>v) swap(u,v); mp[{u,v}]=1;}
	forn(i,2,k+2){
		ll op,u,v; cin>>op>>u>>v;
		if(u>v) swap(u,v);
		ar<ll,2> query={u,v};
		if(op==1) mp[query]=i;
		else upd(query,mp[query],i-1,1,1,k+1),mp.erase(query);
	}
	for(auto&v:mp){ar<ll,2> query=v.fr; upd(query,v.sc,k+1,1,1,k+1);}
	cc=n;
	memset(pa,-1,sizeof(pa));
	dfs(1,1,k+1);
	forn(i,1,k+2) cout << ans[i] << " \n"[i==k+1];
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
 
