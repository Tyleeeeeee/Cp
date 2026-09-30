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
 
constexpr ll mxN=2e6;
ll n,m,a[mxN]{},sbs[mxN],t[mxN][2],pa[mxN],sz[mxN]{},lz[mxN]{},val[mxN],rt=0,id=0;
string s;
bool dir(ll x){return t[pa[x]][1]==x;}
void push_up(ll x){sz[x]=sz[t[x][0]]+1+sz[t[x][1]],sbs[x]=sbs[t[x][0]]+val[x]+sbs[t[x][1]];}
void lazy(ll x){swap(t[x][0],t[x][1]); lz[x]^=1;}
void push_down(ll x){
	if(lz[x]){
		if(t[x][0]) lazy(t[x][0]);
		if(t[x][1]) lazy(t[x][1]);
		lz[x]=0;
	}
}
void rotate(ll x){
	ll y=pa[x],z=pa[y],r=dir(x);
	t[y][r]=t[x][r^1],t[x][r^1]=y;
	if(z) t[z][dir(y)]=x;
	if(t[y][r]) pa[t[y][r]]=y;
	pa[x]=z,pa[y]=x,push_up(y),push_up(x);
}
void splay(ll &z,ll x){
	ll w=pa[z];
	for(ll y;(y=pa[x])!=w;rotate(x)) if(pa[y]!=w) rotate(dir(x)==dir(y)?y:x);
	z=x;
}
void loc(ll &z,ll k){
	ll x=z;
	for(push_down(x);sz[t[x][0]]!=k-1;push_down(x)){
		if(sz[t[x][0]]>=k) x=t[x][0];
		else k-=(sz[t[x][0]]+1),x=t[x][1];
	}
	splay(z,x);
}
void built(){
	forn(i,1,n+3){
		++id,t[id][0]=rt; if(rt) pa[rt]=id; rt=id; val[id]=a[i-1];
	}
	splay(rt,1);
}
void reverse(ll l,ll r){
	loc(rt,l),loc(t[rt][1],r-l+2);
	ll x=t[t[rt][1]][0];
	lazy(x),push_down(x),splay(rt,x);
}
void solve(istream &cin){
	cin>>n>>m;
	forn(i,1,n+1) cin>>a[i];
	built();
	forn(i,1,m+1){
		ll op,l,r; cin>>op>>l>>r;
		if(op==1) reverse(l,r);
		else{
			loc(rt,l),loc(t[rt][1],r-l+2);
			cout << sbs[t[t[rt][1]][0]] << '\n';
		}
	}
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
