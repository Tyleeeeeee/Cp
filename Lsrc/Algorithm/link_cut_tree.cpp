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
ll n,q,t[mxN][2]={0},f[mxN]={0},tag[mxN]={0};
ll dir(ll x){return t[f[x]][1]==x;}
bool isroot(ll x){return t[f[x]][0]!=x && t[f[x]][1]!=x;}
// void push_up(ll x){store[x]=max({va[x],store[t[x][0]],store[t[x][1]]});}
void push_down(ll x){
	if(tag[x]){
		if(t[x][0]) swap(t[t[x][0]][0],t[t[x][0]][1]),tag[t[x][0]]^=1;
		if(t[x][1]) swap(t[t[x][1]][0],t[t[x][1]][1]),tag[t[x][1]]^=1;
		tag[x]=0;
	}
}
void rotate(ll x){
	ll y,z,r; y=f[x],z=f[y],r=dir(x);
	if(!isroot(y)) t[z][dir(y)]=x;
	t[y][r]=t[x][!r],f[t[x][!r]]=y;
	t[x][!r]=y,f[y]=x,f[x]=z;
	// push_up(y),push_up(x);
}
void upd(ll x){
	if(!isroot(x)) upd(f[x]);
	push_down(x);
}
void splay(ll x){
	upd(x);
	for(ll y;y=f[x],!isroot(x);rotate(x)){
		if(!isroot(y)) rotate(dir(x)==dir(y)?y:x);
	}
}
void access(ll x){
	for(ll p=0;x;p=x,x=f[x]){
		splay(x),t[x][1]=p;
		//push_up(x);
	}
}
void makeroot(ll x){
	access(x),splay(x);
	swap(t[x][0],t[x][1]);
	tag[x]^=1;
}
ll find(ll x){
	access(x),splay(x);
	while(t[x][0]) x=t[x][0];
	splay(x);
	return x;
}
void link(ll x,ll y){
	makeroot(x),f[x]=y;
}
void cut(ll x,ll y){
	makeroot(x),access(y),splay(y),t[y][0]=f[x]=0;
}
void solve(istream &cin){
	cin>>n>>q;
	// forn(i,1,n+1){err(i,f[i],t[i][0],t[i][1]);}
	while(q--){
		ll l,r;
		string op; cin>>op>>l>>r;
		if(op=="add"){
			link(l,r);
		}
		else if(op=="rem"){
			cut(l,r);
		}
		else{
			cout << (find(l)==find(r)?"YES":"NO") << '\n';
		}
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
