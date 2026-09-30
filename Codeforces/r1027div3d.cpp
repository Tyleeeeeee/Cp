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

void solve(istream &cin){
	ll n,res;
	cin>>n;
	ll r[n+2][4],c[n+2][4];
	res=inf;
	forn(i,1,n+1) cin>>r[i][0]>>c[i][0],r[i][3]=r[i][2]=r[i][1]=r[i][0],c[i][3]=c[i][2]=c[i][1]=c[i][0];
	if(n==1){cout << 1 << '\n'; return;}
	//0 1 pfx 2 3 sfx
	r[0][0]=c[0][0]=r[0][2]=c[0][2]=r[n+1][0]=c[n+1][0]=r[n+1][2]=c[n+1][2]=0;
	r[0][1]=c[0][1]=r[0][3]=c[0][3]=r[n+1][1]=c[n+1][1]=r[n+1][3]=c[n+1][3]=inf;
	forn(i,1,n+1){
		r[i][0]=max(r[i][0],r[i-1][0]),c[i][0]=max(c[i][0],c[i-1][0]);
		r[i][1]=min(r[i][1],r[i-1][1]),c[i][1]=min(c[i][1],c[i-1][1]);
		r[n-i+1][2]=max(r[n-i+1][2],r[n-i+2][2]),c[n-i+1][2]=max(c[n-i+1][2],c[n-i+2][2]);
		r[n-i+1][3]=min(r[n-i+1][3],r[n-i+2][3]),c[n-i+1][3]=min(c[n-i+1][3],c[n-i+2][3]);
	}
	forn(i,1,n+1){
		ll R,C,area;
		R=max(r[i-1][0],r[i+1][2])-min(r[i-1][1],r[i+1][3])+1;
		C=max(c[i-1][0],c[i+1][2])-min(c[i-1][1],c[i+1][3])+1;
		area=R*C;
		// err(i,area,R,C);
		if(R==1 || C==1) res=min(res,max(n,R==1?C:R));
		else if(area>=n) res=min(res,area);
		else res=min(res,area+min(R,C));
	}
	cout << res << '\n';
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
