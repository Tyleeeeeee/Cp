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

class Node{
	public:
		ll m,fq;
		Node(){}
		Node(ll m,ll fq):m(m),fq(fq){}
		friend Node operator+(const Node &a,const Node &b){
			return (a.m!=b.m?a.m<b.m?a:b:Node{a.m,a.fq+b.fq});
		}
};
constexpr ll off=1e6+1;
constexpr ll mxN=2e6+1;
ll n,lz[mxN<<2]{};
Node t[mxN<<2]{};
vc<ar<ll,3>> rec1,rec2;
void build(ll i=1,ll sl=1,ll sr=mxN){
	ll mid=(sl+sr)>>1;
	if(sl==sr){t[i]=Node{0,1}; return;}
	build(i<<1,sl,mid);
	build(i<<1|1,mid+1,sr);
	t[i]=t[i<<1]+t[i<<1|1];
}
void rad(ll val,ll l,ll r,ll i,ll sl,ll sr){
	if(sr<l || sl>r) return ;
	ll mid=(sl+sr)>>1;
	if(sl==sr){t[i].m+=val; return;}
	if(lz[i]){
		lz[i<<1]+=lz[i];
		t[i<<1].m+=lz[i];
		lz[i<<1|1]+=lz[i];
		t[i<<1|1].m+=lz[i];
		lz[i]=0;
	}
	if(l<=sl && sr<=r){
		lz[i]+=val;
		t[i].m+=val;
		return ;
	}
	rad(val,l,r,i<<1,sl,mid);
	rad(val,l,r,i<<1|1,mid+1,sr);
	t[i]=t[i<<1]+t[i<<1|1];
}
void solve(){
	cin >> n;
	forn(i,0,n){
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2,x1+=off,x2+=off,y1+=off,y2+=off;
		rec1.emp(ar<ll,3>{x1,y1,y2-1});
		rec2.emp(ar<ll,3>{x2,y1,y2-1});
	}
	build();
	sort(all(rec1)),sort(all(rec2));
	//-1e6=1,0=1e6+1,1e6=2e6+1
	ll p=0,b=0,res=0;
	forn(i,1,2e6+2){
		for(;p<rec1.size() && i>=rec1[p][0];p++) rad(1,rec1[p][1],rec1[p][2],1,1,mxN);
		for(;b<p && i>=rec2[b][0];b++) rad(-1,rec2[b][1],rec2[b][2],1,1,mxN);
		res+=(mxN-t[1].fq);
	}
	cout << res << '\n';
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
