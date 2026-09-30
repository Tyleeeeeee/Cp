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
constexpr ll mxN=2e5+1;
ll n,d[2][2];
void solve(){
	cin >> n;
	d[0][0]=d[1][0]=-inf;
	d[0][1]=d[1][1]=inf;
	forn(i,0,n){
		ll x,y;
		cin >> x >> y;
		d[0][0]=max(d[0][0],x+y);
		d[0][1]=min(d[0][1],x+y);
		d[1][0]=max(d[1][0],x-y);
		d[1][1]=min(d[1][1],x-y);
		cout << max(d[0][0]-d[0][1],d[1][0]-d[1][1]) << '\n';
	}
}
//|x2-x1|+|y2-y1|
//x2-x1 + y2-y1 (x2+y2) - (x1+y1)
//x2-x1 + -y2+y1 (x2-y2) - (x1-y1)
//-x2+x1 + y2-y1 -(x2-y2) + (x1-y1)
//-x2+x1 + -y2+y1 -(x2+y2) + (x1+y1)
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
