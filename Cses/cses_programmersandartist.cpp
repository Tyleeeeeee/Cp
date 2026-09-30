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
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=2e5+1;
ll n,p,q;
vc<pll> a(mxN);
void solve(istream &cin){
	cin>>p>>q>>n;
	a[0].fr=a[0].sc=0;
	forn(i,1,n+1) cin>>a[i].fr>>a[i].sc;
	sort(1+a.bg(),1+n+a.bg(),[](pll c,pll d){return (c.fr>d.fr || (c.fr==d.fr && c.sc>d.sc));});
	if(!p || !q){
		ll res=0;
		if(!q){forn(i,1,p+1) res+=a[i].fr;}
		else if(!p){
			sort(1+a.bg(),1+n+a.bg(),[](pll c,pll d){return (c.sc>d.sc || (c.sc==d.sc && c.fr>d.fr));});
			forn(i,1,q+1) res+=a[i].sc;
		}
		cout << res << '\n'; 
		return;
	}
	ll cur,res;
	mls<ll> hp;
	vc<ll> sfx(n+1);
	cur=0;
	forr(i,n,p){
		if(i>p+q) hp.emplace(a[i].sc);
		else{
			sfx[i]=cur;
			hp.emplace(a[i].sc),cur+=*(--hp.ed()),hp.erase(--hp.ed());
		}
	}
	//forn(i,1,n+1){err(i,sfx[i]);}
	a[n+1].fr=res=cur=0,hp.clear();
	forn(i,1,p+1){
		if(i<p)hp.emplace(a[i].sc-a[i].fr);
		cur+=a[i].fr;
	}
	forn(i,p,p+q+1){
		res=max(res,cur+sfx[i]);
		hp.emplace(a[i].sc-a[i].fr),cur=cur+(*(--hp.ed()))+a[i+1].fr,hp.erase(--hp.ed());
	}
	cout << res << '\n';
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
