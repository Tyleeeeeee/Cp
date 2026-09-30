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
ll t[mxN][2]={0},pa[mxN]={0},val[mxN]={0},d[mxN]={0},rt,sz,n,k;
bool dir(ll x){return t[pa[x]][1]==x;}
void push_up(ll x){
	d[x]=d[t[x][0]]+d[t[x][1]]+1;
}
void rotate(ll x){
	ll y,z; y=pa[x],z=pa[y];
	bool r; r=dir(x);
	t[y][r]=t[x][!r];
	t[x][!r]=y;
	if(z) t[z][dir(y)]=x;
	if(t[y][r]) pa[t[y][r]]=y;
	pa[y]=x,pa[x]=z;
	push_up(y),push_up(x);
}
void splay(ll &z,ll x){
	ll w; w=pa[z];
	for(ll y;(y=pa[x])!=w;rotate(x)){
		if(pa[y]!=w) rotate(dir(x)==dir(y)?y:x);
	}
	z=x;
}
void insert(ll v){
	ll x,y; x=rt,y=0;
	for(;x && val[x]!=v; x=t[y=x][v>val[x]]);
	if(x) d[x]++;
	else{
		x=++sz;
		val[x]=v,d[x]=1,pa[x]=y;
		if(y) t[y][v>val[y]]=x;
	}
	splay(rt,x);
}
void find(ll &x,ll y){
	ll u,p; u=x,p=pa[x];
	for(;u && val[u]!=y;u=t[p=u][y>val[u]]);
	splay(x,u?u:p);
}
void find_k(ll &z,ll k){
	ll x; x=z;
	if(!x || k>d[x]) return;
	for(;;){
		if(d[t[x][0]]>=k) x=t[x][0];
		else if(d[t[x][0]]+1>=k) break;
		else k-=(d[t[x][0]]+1),x=t[x][1];
	}
	splay(z,x);
}
ll merge(ll x,ll y){
	if(!x || !y) return x|y;
	find_k(y,1);
	t[y][0]=x,pa[x]=y,push_up(y);
	return y;
}
bool remove(ll v){
	find(rt,v);
	if(!rt || val[rt]!=v) return false;
	pa[t[rt][0]]=pa[t[rt][1]]=0;
	// err(v,rt);
	rt=merge(t[rt][0],t[rt][1]);
	// err(v,rt);
	return true;
}
void solve(istream &cin){
	sz=rt=0;
	cin>>n>>k;
	ll pos; pos=0;
	forn(i,1,n+1) insert(i);
	forn(i,1,n+1){
		pos%=(n-i+1),pos=(pos+k)%(n-i+1);
		find_k(rt,pos+1);
		// err(i,pos+1,val[rt]);
		cout << val[rt] << " \n"[i==n];
		remove(val[rt]);
	}
}

int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
