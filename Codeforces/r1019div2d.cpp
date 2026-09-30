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
ll n;
vc<ll> adj[mxN],in(mxN),res(mxN);
void bfs(){
	ll f,r,q[mxN],st; f=r=0,st=n;
	forn(i,1,n+1) if(!in[i]) q[r=(r+1)%mxN]=i;
	while(f^r){
		ll u; u=q[f=(f+1)%mxN];
		res[u]=st--;
		for(auto&v:adj[u]){
			in[v]--;
			if(!in[v]) q[r=(r+1)%mxN]=v;
		}
	}
}
void solve(istream &cin){
	cin>>n;
	forn(i,1,n+1) adj[i].clear(),in[i]=0;
	ll mx; mx=0;
	vc<pll> a,b;
	forn(i,1,n+1){ll x; cin>>x,mx=max(mx,x); a.emp(pll{x,i});}
	forn(k,1,mx+1){
		ll first,last; first=last=-1;
		forn(i,0,a.size()){
			if(a[i].fr!=k){
				b.emp(a[i]);
				last=i;
				if(first==-1) first=i;
			}
		}
		err(first,last);
		forn(i,1,first+1){
			if(k&1) adj[a[i-1].sc].emp(a[i].sc),in[a[i].sc]++;
			else adj[a[i].sc].emp(a[i-1].sc),in[a[i-1].sc]++;
		}
		forr(i,a.size()-2,last){
			if(k&1) adj[a[i+1].sc].emp(a[i].sc),in[a[i].sc]++;
			else adj[a[i].sc].emp(a[i+1].sc),in[a[i+1].sc]++;
		}
		forn(i,first+1,last+1){
			if(a[i].fr!=k){
				if(k&1) adj[a[i-1].sc].emp(a[i].sc),in[a[i].sc]++;
				else adj[a[i].sc].emp(a[i-1].sc),in[a[i-1].sc]++;
			}
			else if(a[i-1].fr!=k){
				if(k&1) adj[a[i].sc].emp(a[i-1].sc),in[a[i-1].sc]++;
				else adj[a[i-1].sc].emp(a[i].sc),in[a[i].sc]++;
			}
			else adj[a[i-1].sc].emp(a[i].sc),in[a[i].sc]++;
		}
		a.clear(),a.swap(b);
	}
	bfs();
	forn(i,1,n+1) cout << res[i] << " \n"[i==n];
}

int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
