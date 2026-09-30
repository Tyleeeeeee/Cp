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
#define MAX(x,y) (x=max(x,y))
#define MIN(x,y) (x=min(x,y))
constexpr ll mdl1=1e9+7;
constexpr ll mdl2=998244353;
constexpr ll mrt=3;
constexpr ll finv=(mdl1+1)/2;
//constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll

// R-> initial same ans+=R[i] R[i]=n-i-R[i] /ans-=n-i-R[i] R[i]=n-i-R[i]
// L-> initial same ans+=L[i] L[i]=i-1-L[i] /ans-=i-1-L[i] L[i]=i-1-L[i]
// M->same same ans+=(i-1)*(n-i)
//  ->same not same/not same same  not op
//  ->not same not same ans-=(i-1)*(n-i) 
// 8 4
// 10001110
// 3
// 5
// 2
// 3
//R:4 3 2 1 2 1 0 0 
//L:0 0 1 1 2 3 4 2
//M:0 4 5 7 6 8 2 0
//36 23
// 4 2 3 1 2 1 0 0
// 0 0 1 1 2 3 4 2
// 0 4 5 7 6 5 2 0


constexpr ll mxN=2e5+1;
class Node{
	public:
		ll ans,l,r,c0,c1,p0,p1,s0,s1,k;
		Node(){}
		Node(ll ans,ll l,ll r,ll c0,ll c1,ll p0,ll p1,ll s0,ll s1,ll k):ans(ans),l(l),r(r),c0(c0),c1(c1),p0(p0),p1(p1),s0(s0),s1(s1),k(k){}
		friend Node operator +(const Node a,const Node b){
			ll e=(a.r==b.l);
			ll ao=(a.r?a.c1:a.c0), ae=(a.r?a.c0:a.c1);
			ll bo=(b.l?b.c1:b.c0), be=(b.l?b.c0:b.c1); 

			ll ans=a.ans+b.ans;                         
			ans+=bo*a.s1 + ao*b.p1 + bo*ao*(!e);
			ans+=be*a.s1 + ao*b.p0;
			ans+=bo*a.s0 + ae*b.p1;
			ans+=be*a.s0 + ae*b.p0 - be*ae*e;

			ll p0=a.p0, p1=a.p1, d=a.k-e;                
			if(d%2==0){ p0+=b.p0+be*(d/2);     p1+=b.p1+bo*(d/2); }
			else      { p1+=b.p0+be*((d-1)/2); p0+=b.p1+bo*((d+1)/2); }

			ll s0=b.s0, s1=b.s1; d=b.k-e;                 
			if(d%2==0){ s0+=a.s0+ae*(d/2);     s1+=a.s1+ao*(d/2); }
			else      { s1+=a.s0+ae*((d-1)/2); s0+=a.s1+ao*((d+1)/2); }

			return {ans,a.l,b.r,a.c0+b.c0,a.c1+b.c1,p0,p1,s0,s1,a.k+b.k-e};
		}
};
ll n,q;
string s;
Node t[mxN<<1];
Node query(ll l,ll r){
	ll okL=0,okR=0;
	Node L,R;
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1){L=(okL?L+t[l]:t[l]); okL=1,l++;}
		if(r&1^1){R=(okR?t[r]+R:t[r]); okR=1; r--;}
	}
	if(!okL) return R;
	if(!okR) return L;
	return L+R;
}
void solve(){
	cin >> n >> q >> s;
	forn(i,1,n+1){ll c=s[i-1]-'0'; t[i+n-1]={0,c,c,c==0,c==1,0,0,0,0,1};}
	forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];
	cout << query(1,n).ans << ' ';
	for(ll x;q--;){
		cin >> x,s[x-1]=(s[x-1]=='0'?'1':'0');
		ll y=s[x-1]-'0';
		for(t[x+=n-1]={0,y,y,y==0,y==1,0,0,0,0,1};x>>=1;t[x]=t[x<<1]+t[x<<1|1]);
		cout << query(1,n).ans << " \n"[!q];
	}
}

int main()
{
    fast_io;
    int testcase;
    cin>>testcase;
    while(testcase--)
        solve();
    return 0;
}
