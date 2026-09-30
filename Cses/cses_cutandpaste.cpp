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
#include<cctype>
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
using ll=int;
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
#define fast_io cin.tie(0),ios_base::sync_with_stdio(false)
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
// constexpr ll mdl1=1e9+7;
// constexpr ll mdl2=998244353;
// constexpr ll mrt=3;
// constexpr ll finv=(mdl1+1)/2;
// constexpr ll inf=1e18;
// constexpr ll INF=0x3f3f3f3f3f3f3f3f;
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

constexpr ll mxN=2e5+5;
ll n,m,t[mxN][2],f[mxN],d[mxN],val[mxN],id=0,rt=0;
string s;
bool dir(ll x){return t[f[x]][1]==x;}
void pu(ll x){d[x]=d[t[x][0]]+1+d[t[x][1]];}
void rotate(ll x){
	ll y=f[x],z=f[y],r=dir(x);
	t[y][r]=t[x][r^1],t[x][r^1]=y;
	if(z) t[z][dir(y)]=x; if(t[y][r]) f[t[y][r]]=y;
	f[x]=z,f[y]=x,pu(y),pu(x);
}
void splay(ll &z,ll x){
	ll w=f[z];
	for(ll y;(y=f[x])^w;rotate(x)) if(f[y]^w) rotate(dir(y)==dir(x)?y:x);
	z=x;
}
void built(){
	forn(i,1,n+3){
		id++; t[id][0]=rt,val[id]=i-1; if(rt) f[rt]=id; rt=id;
	}
	splay(rt,1);
}
void loc(ll &z,ll k){
	ll x=z;
	for(;d[t[x][0]]+1!=k;){
		if(k<=d[t[x][0]]) x=t[x][0];
		else k-=d[t[x][0]]+1,x=t[x][1];
	}
	splay(z,x);
}
void cap(ll l,ll r){
	loc(rt,l);
	loc(t[rt][1],r-l+2);
	ll x=t[t[rt][1]][0];
	f[x]=0,t[t[rt][1]][0]=0,pu(t[rt][1]),pu(rt);
	loc(rt,d[rt]-1),loc(x,1),t[t[rt][1]][0]=x,f[x]=t[rt][1],splay(rt,x);
}
void print(ll x){
	if(!x) return;
	print(t[x][0]),cout << s[val[x]-1],print(t[x][1]);
}
void print(){
	loc(rt,1);
	loc(t[rt][1],n+1);
	print(t[t[rt][1]][0]);
}
void solve(){
	cin>>n>>m;
	cin.ignore();
	getline(cin,s);
	built();
	while(m--){
		ll l,r; cin>>l>>r; cap(l,r);
	}
	print();
}
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
