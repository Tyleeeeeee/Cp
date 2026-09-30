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
 
ll n;
ll solve(vc<ll> &a){
	ll ans; ans=0;
	vc<ll> vs(n+1,0);
	forn(i,1,n+1){
		if(!vs[i]){
			ans++;
			for(ll j=a[i];j^i;j=a[j]) vs[j]=1;
		}
	}
	return ans;
}
void solve(istream &cin){
	cin>>n;
	vc<ll> a(n+1),b[2];
	b[0].emp(0),b[1].emp(0);
	forn(i,1,n+1) cin>>a[i],b[i&1].emp(a[i]);
	ll par; par=solve(a);
	sort(1+b[0].bg(),b[0].ed()),sort(1+b[1].bg(),b[1].ed());
	// forn(i,0,2) forn(j,1,b[i].size()) {err(i,j,b[i][j]);}
	forn(i,1,n+1) a[i]=b[i&1][(i+1)/2];
	// forn(i,1,n+1) cout << a[i] << " \n"[i==n];
	if((par&1)!=(solve(a)&1)) swap(a[n],a[n-2]);
	forn(i,1,n+1) cout << a[i] << " \n"[i==n];
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
