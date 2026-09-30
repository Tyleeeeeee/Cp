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
#pragma GCC optimize ("03")
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
 
ll n,m,res=0;
string s,rs;
vc<ll> zf(const string x){
	ll L=x.length(),l,r=-1;
	vc<ll> z(L,0);
	forn(i,1,L){
		if(r>i) z[i]=min(z[i-l],r-i);
		while(i+z[i]<L && x[z[i]]==x[i+z[i]]) z[i]++;
		if(i+z[i]>r) l=i,r=i+z[i];
	}
	return z;
}
vc<ll> kmp(const string x){
	ll L=x.length();
	vc<ll> k(L,0);
	forn(i,1,L){
		ll j=k[i-1];
		while(j>0 && x[j]!=x[i]) j=k[j-1];
		if(x[j]==x[i]) k[i]=j+1;
	}
	return k;
}
void solve(istream &cin){
	cin>>s>>m;
	rs=s,reverse(all(rs));
	n=s.length();
	while(m--){
		ll x,ok=0; string c,rc; cin>>c,rc=c,x=c.length(),reverse(all(rc));
		if(x==1) continue;
		vc<ll> z=zf(c+"#"+s),k=kmp(rc+"#"+rs),pfx(x,inf),sfx(x,-1);
		forn(i,x+1,x+1+n){
			if(z[i]==x || k[i]==x){ok=1,res++; break;}
			if(z[i]) pfx[z[i]]=min(pfx[z[i]],i+z[i]-1-x);
			if(k[i]) sfx[k[i]]=max(sfx[k[i]],n-(i-x)+1);
		}
		if(!ok)
			forn(i,1,x) if(pfx[i]<sfx[x-i]){res++; break;}
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
