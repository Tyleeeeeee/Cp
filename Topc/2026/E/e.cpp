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
constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
constexpr ll mxN=100+102;
ll n,a[mxN][mxN],b[mxN][mxN];
bool checkrow(ll ind){
	for(ll i=0,ls=-1;i<n;i++){if(!b[ind][i] && a[ind][i]<ls) return false; if(!b[ind][i]) ls=a[ind][i];}
	return true;
}
bool checkcol(ll ind){
	for(ll i=0,ls=-1;i<n;i++){if(b[i][ind]==1 && a[i][ind]<ls) return false; if(b[i][ind]==1) ls=a[i][ind];}
	return true;
}
void solve(){
	cin >> n;
	forn(i,0,n) forn(j,0,n) cin >> a[i][j];
	forn(i,0,n){
		forn(j,0,n){
			ll oi=(a[i][j]-1)/n,oj=(a[i][j]-1)%n;
			if(oi!=i && oj!=j){cout << "No" << '\n'; return;}
			//0=red 1=blue 2=free
			if(oi!=i) b[i][j]=1;
			if(oi==i && oj==j) b[i][j]=2;
		}
	}
	forn(i,0,n) 
		forn(j,0,n){
 			if(b[i][j]==2){b[i][j]=0; if(!checkrow(i)) b[i][j]=2;}
 			if(b[i][j]==2){b[i][j]=1; if(!checkcol(j)) b[i][j]=2;}
			if(b[i][j]==2){cout << "No" << '\n'; return;}
		}
	forn(i,0,n) if(!checkrow(i) || !checkcol(i)){cout << "No" << '\n'; return;}
	cout << "Yes" << '\n';
}
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
