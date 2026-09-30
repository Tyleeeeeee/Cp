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
//constexpr ll inf=1e18;
//constexpr ll INF=0x3f3f3f3f3f3f3f3f;
#pragma GCC target("popcnt")
#pragma GCC target("lzcnt")
#pragma GCC optimize ("O3")
//__builtin_popcountll
//__builtin_parityll
//__builtin_clzll
//__builtin_ctzll
 
class Node{
	public:
	ll n00,n01,n10,n11;
	Node(){}
	Node(ll n00,ll n01,ll n10,ll n11):n00(n00),n01(n01),n10(n10),n11(n11){}
	friend Node operator+(const Node a,const Node b){
		return {a.n00+b.n00,a.n01+b.n01,a.n10+b.n10,a.n11+b.n11};
	}
};
constexpr ll mxN=2e5+1;
ll n,q;
string s,ts;
Node t[mxN<<1];
Node query(ll l,ll r){
	Node ans={0,0,0,0};
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1) ans=ans+t[l++];
		if(r&1^1) ans=ans+t[r--];
	}
	return ans;
}
void solve(){
	cin >> n >> q >> s >> ts;
	forn(i,1,n+1){
		ll b=s[i-1]-'0',c=ts[i-1]-'0';
		t[i+n-1]={!b&&!c,!b&&c,b&&!c,b&&c};
	}
	forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];
	for(ll l,r,x;q--;){
		cin >> l >> r;
		auto [n00,n01,n10,n11]=query(l,r);
		x=min(n01,n10);
		//err(n00,n01,n10,n11,x,r-l+1-x);
		if(r-l+1-2*x-n00-n11>n00+n11){cout << "NO" << '\n';}
		else cout << "YES" << '\n';
	}
}
int main()
{
    fast_io;
    int testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve();
    return 0;
}
