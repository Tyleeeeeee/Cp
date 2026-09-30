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
#pragma GCC target("lzcnt")
#pragma GCC optimize ("03")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
constexpr ll mxN=2e5+5;
ll n,lz[mxN]{};
vc<pll> t(mxN<<1);
void apply(ll p,ll val){t[p].fr+=val,t[p].sc+=val; if(p<n) lz[p]+=val;}
void built(ll p){
	for(;p>>=1;){
		if(!lz[p]) t[p].fr=max(t[p<<1].fr,t[p<<1|1].fr),t[p].sc=min(t[p<<1].sc,t[p<<1|1].sc);
	}
}
void push(ll p){
	for(ll h=63-__builtin_clzll(p);h;h--){
		if(lz[p>>h]){
			apply((p>>h)<<1,lz[p>>h]);
			apply((p>>h)<<1|1,lz[p>>h]);
			lz[p>>h]=0;
		}
	}
}
void upd(ll l,ll r,ll val){
	ll L=l+=n-1,R=r+=n-1;
	push(L),push(R);
	for(;l<=r;l>>=1,r>>=1){
		if(l&1) apply(l++,val);
		if(!(r&1)) apply(r--,val);
	}
	built(L),built(R);
}
pll query(ll l,ll r){
	push(l+=n-1),push(r+=n-1);
	pll res({0,inf});
	for(;l<=r;l>>=1,r>>=1){
		if(l&1) res.fr=max(res.fr,t[l].fr),res.sc=min(res.sc,t[l].sc),l++;
		if(!(r&1)) res.fr=max(res.fr,t[r].fr),res.sc=min(res.sc,t[r].sc),r--;
	}
	return res;
}
void solve(istream &cin){
	cin>>n;
	forn(i,1,n+1){
		ll c,op; cin>>c>>op;
		upd(1,c,(op==1?1:-1));
		auto [mx,mn]=query(1,n);
		if(mx*mn>=0) cout << (mx>0?'>':'<') << '\n';
		else cout << '?' << '\n';
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
