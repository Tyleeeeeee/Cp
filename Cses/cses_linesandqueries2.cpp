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

class Point{
	public:
		ll x,y;
		friend ll ang(const Point &a,const Point &b,const Point &c){
			return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
		}
		friend ll dis(const Point &a,const Point &b){
			return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
		}
};
class line {
	public:
	ll m,c;
	line(){m=0,c=-inf-1;}
	line(ll m,ll c):m(m),c(c){}
	ll cal(ll x){return m*x+c;}
};
constexpr ll mxN=1e5+5;
ll n;
line t[mxN<<2];
void insert(line x,ll l,ll r,ll i,ll sl,ll sr){
	if(sr<l || r<sl || l>r) return;
	ll mid=(sl+sr)>>1;
	if(l<=sl && sr<=r){
		bool lf=t[i].cal(sl-1)<x.cal(sl-1),mf=t[i].cal(mid-1)<x.cal(mid-1),rf=t[i].cal(sr-1)<x.cal(sr-1);
		if(mf) swap(x,t[i]);
		if(sl==sr) return;
		if(lf^mf) insert(x,l,r,i<<1,sl,mid);
		if(rf^mf) insert(x,l,r,i<<1|1,mid+1,sr);
		return;
	}
	insert(x,l,r,i<<1,sl,mid);
	insert(x,l,r,i<<1|1,mid+1,sr);
}
ll query(ll x,ll i,ll sl,ll sr){
	ll mid=(sl+sr)>>1;
	if(sl==sr) return t[i].cal(x-1);
	if(x<=mid) return max(t[i].cal(x-1),query(x,i<<1,sl,mid));
	else return max(t[i].cal(x-1),query(x,i<<1|1,mid+1,sr));
}
void solve(){
	cin >> n;
	forn(i,0,n){
		ll op;
		cin >> op;
		if(op==1){
			ll a,b,l,r;
			cin >> a >> b >> l >> r;
			line x{a,b};
			insert(x,l+1,r+1,1,1,mxN-4);
		}
		else{
			ll x;
			cin >> x;
			x=query(x+1,1,1,mxN-4);
			if(x>-inf-1) cout << x << '\n';
			else cout << "NO" << '\n';
		}
	}
}
//g=(y2-y1)/(x2-x1)
//(y-y1)=(x-x1)*g
//y=x*g - x1*g + y1
int main()
{
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
