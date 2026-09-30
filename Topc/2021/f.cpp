#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define DEBUG 1
   #if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
       template<typename T,typename... Args>
       inline void debug (const T& val,const Args&... args){
           cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
       }
       #define terr cerr << "I am here" << '\n'
   #endif
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back
#define upb upper_bound
#define all(x) x.begin(),x.end()
using i128=__int128;

//10010103 200
//1001003 100
//1000100 100
//10001000 100
constexpr ll inf=0x3f3f3f3f3f3f3f3f;

//0 0 1 0 1 0 0 1 1 1 0 1 0 0 0 1 1 1 0 0
//1 1 0 1 0 1 1 0 0 0 0 1 0 0 0 1 1 1 0 0
constexpr ll mxN=2e5+1;
class Node{
	public:
		ll ans,l,r,lasl,lasr,len;
		Node(){}
		Node(ll ans,ll l,ll r,ll lasl,ll lasr,ll len):ans(ans),l(l),r(r),lasl(lasl),lasr(lasr),len(len){}
		friend Node operator+(const Node a,const Node b){
			if(!a.ans) return b;
			if(!b.ans) return a;
			return {a.ans+b.ans+(a.r^b.l)*(a.lasr*b.lasl),a.l,b.r,a.lasl==a.len?a.lasl+(a.r^b.l)*b.lasl:a.lasl,b.lasr==b.len?b.lasr+(a.r^b.l)*a.lasr:b.lasr,a.len+b.len};
		}
};
ll n,q,a[mxN],lz[mxN<<2];
Node t[mxN<<2];
void build(ll i,ll sl,ll sr){
	if(sl>sr) return;
	ll m=sl+sr>>1;
	if(sl==sr){ t[i]=Node{1,a[sl],a[sl],1,1,1}; return;}
	build(i<<1,sl,m),build(i<<1|1,m+1,sr);
	t[i]=t[i<<1]+t[i<<1|1];
}
Node query(ll i,ll sl,ll sr,ll l,ll r){
	if(r<sl || l>sr || l>r) return {0,0,0,0,0,0};
	ll m=sl+sr>>1;
	if(l<=sl && sr<=r) return t[i];
	if(lz[i]){
		t[i<<1].l^=1,t[i<<1].r^=1,lz[i<<1]^=1;
		t[i<<1|1].l^=1,t[i<<1|1].r^=1,lz[i<<1|1]^=1;
		lz[i]=0;
	}
	return query(i<<1,sl,m,l,r)+query(i<<1|1,m+1,sr,l,r);
}
void rad(ll i,ll sl,ll sr,ll l,ll r){
	if(r<sl || l>sr || l>r) return;
	ll m=sl+sr>>1;
	if(l<=sl && sr<=r){
		t[i].l^=1,t[i].r^=1;
		if(sl!=sr) lz[i]^=1; 
		return;
	}
	if(lz[i]){
		t[i<<1].l^=1,t[i<<1].r^=1,lz[i<<1]^=1;
		t[i<<1|1].l^=1,t[i<<1|1].r^=1,lz[i<<1|1]^=1;
		lz[i]=0;
	}
	rad(i<<1,sl,m,l,r),rad(i<<1|1,m+1,sr,l,r);
	t[i]=t[i<<1]+t[i<<1|1];
}
void solve(){
	cin >> n >> q;
	forn(i,1,n+1) cin >> a[i];
	build(1,1,n);
	for(ll op,l,r;q--;){
		cin >> op >> l >> r;
		if(op==1) rad(1,1,n,l,r);
		else cout << query(1,1,n,l,r).ans << '\n';;
	}
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	int testcase;
	testcase=1;
	//cin >> testcase;
	while(testcase--) solve();
	return 0;
}
