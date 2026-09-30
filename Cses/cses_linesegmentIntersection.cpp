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
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

class Point{
	public:
		ll x,y;
		Point(){}
		Point(ll X,ll Y):x(X),y(Y){}
		friend istream& operator>>(istream& in,Point &a){in>>a.x>>a.y; return in;}
		friend Point operator-(const Point &a,const Point &b){return {a.x-b.x,a.y-b.y};}
		friend ll operator*(const Point &a,const Point &b){return a.x*b.x+a.y*b.y;}
		friend ll operator^(const Point &a,const Point &b){return a.x*b.y-b.x*a.y;}
};
vc<Point> a(4);
bool on(Point &a,Point &b,Point &c){
	if((b-a)^(c-a)) return false;
	return (0<=(b-a)*(c-a) && (b-a)*(c-a)<=(b-a)*(b-a));
}
ll sg(ll x){return (x>0?1:x<0?-1:0);}
bool ok(){
	ll f1=sg((a[1]-a[0])^(a[3]-a[0]))*sg((a[1]-a[0])^(a[2]-a[0])),f2=sg((a[3]-a[2])^(a[0]-a[2]))*sg((a[3]-a[2])^(a[1]-a[2]));
	if(f1<0 && f2<0) return true;
	if(f1>0 || f2>0) return false;
	return (on(a[0],a[1],a[2]) || on(a[0],a[1],a[3]) || on(a[2],a[3],a[0]) || on(a[2],a[3],a[1]));
}
void solve(istream &cin){
	forn(i,0,4) cin>>a[i];
	cout << (ok()?"YES":"NO") << '\n';
}
int main()
{
    fast_io;
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
