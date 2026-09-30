 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
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
// char dir[4]={'L','D','R','U'};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=3e5+5;
ll n,t[mxN<<1],lz[mxN]{};
void built(){forr(i,n-1,1)t[i]=max(t[i<<1],t[i<<1|1]);}
void apply(ll p,ll val){t[p]+=val; if(p<n) lz[p]+=val;}
void push(ll p){for(ll h=63-__builtin_clzll(p);h;h--) if(lz[p>>h]){apply((p>>h)<<1,lz[p>>h]),apply((p>>h)<<1|1,lz[p>>h]),lz[p>>h]=0;}}
void built(ll p){for(;p>>=1;)if(!lz[p]) t[p]=max(t[p<<1],t[p<<1|1]);}
void rad(ll l,ll r,ll val){
	    ll l0=l+=n-1,r0=r+=n-1; push(l0),push(r0);
		    for(;l<=r;l>>=1,r>>=1){if(l&1) apply(l++,val); if(r&1^1) apply(r--,val);}
			    built(l0),built(r0);
}
void pst(ll p,ll val){push(p+=n-1);for(t[p]=val;p>>=1;t[p]=max(t[p<<1],t[p<<1|1]));}
ll query(ll l,ll r){ ll ans=0; push(l+=n-1),push(r+=n-1); for(;l<=r;l>>=1,r>>=1){if(l&1) ans=max(ans,t[l++]); if(r&1^1) ans=max(ans,t[r--]);} return ans;}
//ll query(ll p){push(p+=n-1); return t[p];}
void solve(){
	cin >> n;
	n++;
	forn(i,0,2*n){
		t[i]=0;
		if(i<n) lz[i]=0;
	}
	forn(i,0,n-1){
		ll x; cin >> x;
		rad(1,x,1);
		pst(x+1,0);
		cout <<  query(1,n) << " \n"[i==n-2];
	}
}
//0 1 2 3
//0 1 1 0
int main()
{
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
