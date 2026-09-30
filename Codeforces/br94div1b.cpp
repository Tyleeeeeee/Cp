 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Ying with me
#include<bits/stdc++.h>
using namespace std;
using ii=int;
// using ll=int;
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

//1 3 6 10 15
//   

class Node{
	public:
		ll l,lk,cnt,rcn,nxt[26];
		Node(){}
		Node(ll l,ll lk,ll cnt):l(l),lk(lk),cnt(cnt){memset(nxt,0,sizeof(nxt));}
};
constexpr ll mxN=1e5+1;
ll n,k,id,dp[mxN<<1]{};
string s;
Node t[mxN<<1];
void sfat(string &s){
	id=0,t[0].l=0,t[0].lk=-1,t[0].cnt=0,t[0].rcn=0;
	for(ll i=0,p,q,c,ls=0,cr;i<n;++i){
		cr=++id,c=s[i]-'a',t[cr].l=t[ls].l+1,t[cr].cnt=1,t[cr].rcn=0;
		for(p=ls;(~p) && !t[p].nxt[c];t[p].nxt[c]=cr,p=t[p].lk);
		if(!(~p)) t[cr].lk=0;
		else{
			q=t[p].nxt[c];
			if(t[q].l==t[p].l+1) t[cr].lk=q;
			else{
				ll cl=++id;
				t[cl].l=t[p].l+1,t[cl].lk=t[q].lk,t[cl].cnt=0,t[cl].rcn=1,memcpy(t[cl].nxt,t[q].nxt,sizeof(t[q].nxt));
				for(;(~p) && t[p].nxt[c]==q;t[p].nxt[c]=cl,p=t[p].lk);
				t[q].lk=t[cr].lk=cl;
			}
		}
		t[t[cr].lk].rcn++;
		ls=cr;
	}
}
void sub(){
	queue<ll> q;
	forn(i,1,id+1) if(!t[i].rcn) q.emplace(i);
	while(!q.empty()){
		auto u=q.front(); q.pop();
		if(!u) break;
		ll v=t[u].lk;
		t[v].cnt+=t[u].cnt;
		t[v].rcn--;
		if(!t[v].rcn) q.emplace(v);
	}
}
ll dfs(ll u=0){
	if(dp[u]) return dp[u];
	forn(i,0,26){
		if(t[u].nxt[i]){
			dp[u]+=dfs(t[u].nxt[i]);
		}
	}
	return dp[u]+=t[u].cnt;
}
void res(ll u=0){
	if(k<=t[u].cnt) return;
	else k-=t[u].cnt;
	forn(i,0,26){
		if(!t[u].nxt[i]) continue;
		if(k>dp[t[u].nxt[i]]) k-=dp[t[u].nxt[i]];
		else{
			cout << char(i+'a');
			return res(t[u].nxt[i]);
		}
	}
}
void solve(istream &cin){
	cin >> s >> k,n=s.length();
	if(k>n*(n+1)/2){cout << "No such line." << '\n'; return;}
	sfat(s);
	sub();
	t[0].cnt=0;
	dfs();
	res();
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
