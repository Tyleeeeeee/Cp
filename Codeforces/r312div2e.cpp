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
 
constexpr ll mxN=1e5;
ll n,q,t[26][mxN<<1]={0},lz[26][mxN],cnt[26];
string s;
ll msb(ll x){forr(i,20,0) if(x&(1<<i)) return i; return -1;}
void built(){
	forn(i,0,26)
		forr(j,mxN-1,1) t[i][j]=t[i][j<<1]+t[i][j<<1|1];
}
void apply(ll i,ll p,ll val,ll k){t[i][p]=val*k; if(p<mxN) lz[i][p]=val;}
void push(ll i,ll p){
	for(ll h=msb(mxN);h;h--){
		if(lz[i][p>>h]!=-1){
			apply(i,(p>>h)<<1,lz[i][p>>h],1<<(h-1));
			apply(i,(p>>h)<<1|1,lz[i][p>>h],1<<(h-1));
			lz[i][p>>h]=-1;
		}
	}
}
void built(ll i,ll p){
	for(;p>>=1;){
		if(lz[i][p]==-1) t[i][p]=t[i][p<<1]+t[i][p<<1|1];
	}
}
ll query(ll i,ll l,ll r){
	if(l>r) return 0;
	ll ans; ans=0;
	push(i,l+=mxN-1),push(i,r+=mxN-1);
	for(;l<=r;l>>=1,r>>=1){
		if(l&1) ans+=t[i][l++];
		if(!(r&1)) ans+=t[i][r--];
	}
	return ans;
}
ll query(ll i,ll p){
	push(i,p+=mxN-1);
	return t[i][p];
}
void rst(ll i,ll l,ll r,ll val){
	if(l>r) return;
	ll lo,ro,k; lo=(l+=mxN-1),ro=(r+=mxN-1),k=1;
	push(i,lo),push(i,ro);
	for(;l<=r;l>>=1,r>>=1,k<<=1){
		if(l&1) apply(i,l++,val,k);
		if(!(r&1)) apply(i,r--,val,k);
	}
	built(i,lo),built(i,ro);
}
void push_down(){
	forn(i,0,s.length()){
		forn(j,0,26){
			if(query(j,i+1)) {s[i]=(char)(j+'a'); break;}
		}
	}
}
void solve(istream &cin){
	cin>>n>>q>>s;
	memset(lz,-1,sizeof(lz));
	forn(i,0,s.length()) t[s[i]-'a'][i+mxN]=1;
	built();
	while(q--){
		ll l,r,k; cin>>l>>r>>k;
		forn(i,0,26) {
			cnt[i]=query(i,l,r),rst(i,l,r,0);
		}
		ll cur; cur=l;
		if(k) forn(i,0,26) rst(i,cur,cur+cnt[i]-1,1),cur+=cnt[i];
		else forr(i,25,0) rst(i,cur,cur+cnt[i]-1,1),cur+=cnt[i];
	}
	push_down();
	cout << s << '\n';
}
 
int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
