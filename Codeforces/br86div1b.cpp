 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
using namespace std;
using ii=int;
using ll=int;
// using ll=long long;
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
// constexpr ll inf=1e18;
// constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
//0=L 1=D 2=R 3=U
//ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
// char dir[4]={'L','D','R','U'};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
//ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

//1000000000949747713=2^29*3*73*8505229 c=3*73*8505229=1862645151
//root=5  max_len=2^29
// constexpr ll mod=1000000000949747713;
// constexpr ll root=944855867104044178;
// constexpr ll root_inv=190817968088312480;
// constexpr ll maX=1LL<<29;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const ll M = 991831889;
// const ll C = uniform_int_distribution<ll>(0.1 * M, 0.9 * M)(rng);


constexpr ll mxN=2e3+1;
ll n,m,Z[mxN]{},K[mxN]{},st[mxN],id=0,res=0,tr[2000*1999/2+1][26],en[2000*1999/2+1]{},store=0;
string t,sb,se;
void zf(string &s){
	ll l,r;
	l=r=-1;
	vc<ll> z(s.length(),0);
	//[0,n][n+1,s.length()-1]
	forn(i,1,s.length()){
		if(i<r) z[i]=min(r-i,z[i-l]);
		while(i+z[i]<s.length() && s[z[i]]==s[i+z[i]]) z[i]++;
		if(i+z[i]>r) l=i,r=i+z[i];
		Z[max(0,i-n-1)]=z[i];
	}
}
ll kmp(string &s){
	vc<ll> k(s.length(),0);
	forn(i,1,s.length()){
		ll j=k[i-1];
		while(j && s[i]!=s[j]) j=k[j-1];
		if(s[i]==s[j]) k[i]=j+1;
		K[max(0,i-m-1)]=k[i];
	}
	return k[s.length()-1];
}
void insert(string &tmp,ll ref){
	ll v=0,top=id;
	forn(i,0,tmp.length()){
		ll c=tmp[i]-'a';
		if(!(~tr[v][c])) tr[v][c]=++store;
		v=tr[v][c];
		if(i==st[top]-ref) res+=(!en[v]),en[v]++,top--;
	}
}
void solve(istream &cin){
	cin >> t >> sb >> se;
	memset(tr,-1,sizeof(tr));
	n=sb.length(),m=se.length();
	string t1=sb+'#'+t;
	string t2=se+'#'+t;
	string t3=se+'#'+sb;
	ll kk=kmp(t3);
	zf(t1),kmp(t2);
	//forn(i,0,t.length()){err(i,Z[i],K[i]);}
	for(ll i=t.length()-1;~i;i--){
		//err(i,i+n+m-1-kk,t.length());
		//if(i+n+m-1-kk<t.length()) {err(K[i+n+m-1-kk],m);}
		if(ll j=i+n+m-1-kk; j<t.length() && K[j]==m) st[++id]=j;
		if(Z[i]==n){
			if(id){
				string tmp=t.substr(i,st[1]-i+1);
				insert(tmp,i);
			}
		}
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
