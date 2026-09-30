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

constexpr ll mxN=2e5+1;
ll n,q,cnt;
vc<ar<ll,5>> st;
vc<ar<ll,3>> t[mxN<<4];
vc<ll> adj(mxN),res(mxN),pa(mxN,-1),k(mxN),parity(mxN,0);
ar<ll,2> find(ll x){
	if(pa[x]<0) return {x,0};
	auto [a,b]=find(pa[x]);
	return {a,b^parity[x]};
}
void un(ll x,ll y){
	auto [x1,x2]=find(x);
	auto [y1,y2]=find(y);
	if(x1==y1){
		cnt^=((x2^y2^1)==0);
		st.emp(ar<ll,5>{-1,-1,-1,-1,(x2^y2^1)==0});
		return ;
	}
	if(-pa[x1]>-pa[y1]) swap(x1,y1),swap(x2,y2);
	st.emp(ar<ll,5>{x1,pa[x1],parity[x1],y1,pa[y1]});
	pa[y1]+=pa[x1],parity[x1]=x2^y2^1,pa[x1]=y1;
	return ;
}
void rollb(){
	if(!st.empty()){
		auto [u,U,P,v,V]=st.back(); st.pop_back();
		if(u!=-1)
			pa[u]=U,pa[v]=V,parity[u]=P;
		else cnt^=V;
	}
}
void upd(ar<ll,3> query,ll l,ll r,ll i,ll sl,ll sr){
	if(sl>sr || l>r) return;
	if(l==sl && r==sr){
		// err(l,r);
		t[i].emp(query);
		return;
	}
	ll mid; mid=(sl+sr)>>1;
	upd(query,l,min(r,mid),i<<1,sl,mid);
	upd(query,max(l,mid+1),r,i<<1|1,mid+1,sr);
}
void dfs(ll i,ll sl,ll sr){
	for(auto&v:t[i]){
		un(v[0],v[1]);
	}
	if(sl==sr){
		res[sl]=k[sl]%3;
		// err(sl,res[sl],cnt,q&1);
		if(res[sl]==2) res[sl]=((cnt+(n&1))&1?2:1);
	}
	else{
		ll mid; mid=(sl+sr)>>1;
		dfs(i<<1,sl,mid);
		dfs(i<<1|1,mid+1,sr);
	}
	// for(auto&v:t[i]){
	// 	if(v[2]) rollb(),v[2]=0;
	// }
	forr(j,t[i].size()-1,0){
		rollb(),t[i][j][2]=0;
	}
}
void solve(istream &cin){
	cin>>n>>q;
	vc<ll> ls(n+1,1);
	forn(i,1,n+1) cin>>adj[i];
	forn(i,1,q+1){
		ll u,v; cin>>u>>v>>k[i];
		// err(u,adj[u],ls[u],i-1);
		upd({u,adj[u],0},ls[u],i-1,1,1,q);
		adj[u]=v,ls[u]=i;
	}
	forn(i,1,n+1) {
		// err(i,adj[i],ls[i],q);
		upd({i,adj[i],0},ls[i],q,1,1,q);
	}
	cnt=0;
	dfs(1,1,q);
	forn(i,1,q+1) cout << res[i] << '\n';
}

int main()
{
    fast_io;
    // ifstream cin("connect.in");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
