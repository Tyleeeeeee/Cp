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
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=2e5+1;
constexpr ll mxT=7e6+1;
ll n,q,t[mxT],a[mxN],lc[mxT],rc[mxT],rt[mxN],rsc,sz;
void built(ll i,ll sl,ll sr){
	if(sl==sr){t[i]=a[sl]; return;}
	ll mid; mid=(sl+sr)>>1;
	lc[i]=++sz,rc[i]=++sz;
	built(lc[i],sl,mid);
	built(rc[i],mid+1,sr);
	t[i]=t[lc[i]]+t[rc[i]];
}
ll pst(ll pos,ll val,ll i,ll sl,ll sr){
	ll x; x=++sz;
	if(sl==sr){t[x]=val; return x;}
	ll mid; mid=(sl+sr)>>1;
	if(pos<=mid) lc[x]=pst(pos,val,lc[i],sl,mid),rc[x]=rc[i];
	else lc[x]=lc[i],rc[x]=pst(pos,val,rc[i],mid+1,sr);
	t[x]=t[lc[x]]+t[rc[x]];
	return x;
}
ll query(ll l,ll r,ll i,ll sl,ll sr){
	if(l>sr || r<sl) return 0;
	if(l<=sl && sr<=r) return t[i];
	ll mid; mid=(sl+sr)>>1;
	return query(l,r,lc[i],sl,mid)+query(l,r,rc[i],mid+1,sr);
}
void solve(istream &cin){
	cin>>n>>q;
	sz=rsc=0;
	forn(i,1,n+1) cin>>a[i];
	rt[++rsc]=++sz;
	built(rt[1],1,n);
	while(q--){
		ll op; cin>>op;
		if(op==3){
			ll k; cin>>k;
			rt[++rsc]=++sz;
			lc[rt[rsc]]=lc[rt[k]],rc[rt[rsc]]=rc[rt[k]],t[rt[rsc]]=t[lc[rt[rsc]]]+t[rc[rt[rsc]]];
		}
		else if(op==1){
			ll k,a,x; cin>>k>>a>>x;
			rt[k]=pst(a,x,rt[k],1,n);
		}
		else{
			ll k,a,b; cin>>k>>a>>b;
			cout << query(a,b,rt[k],1,n) << '\n';
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
