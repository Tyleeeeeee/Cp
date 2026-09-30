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
//1000000000949747713=2^29*3*73*8505229 c=3*73*8505229=1862645151
//root=5  max_len=2^29
// constexpr ll mod=1000000000949747713;
// constexpr ll root=944855867104044178;
// constexpr ll root_inv=190817968088312480;
// constexpr ll maX=1LL<<29;

class FFT{
	public:
		ll mod,root,root_inv,maX,M,M_inv;
		FFT(){}
		FFT(ll a,ll b,ll c,ll d,ll e,ll f):mod(a),root(b),root_inv(c),maX(d),M(e),M_inv(f){}
		ll fsp(ll a,ll m){
			ll ans=1;
			while(m){
				if(m&1) ans=(ans*a)%mod;
				a=(a*a)%mod,m>>=1;
			}
			return ans;
		}
		void fft(ll sz,vc<ll> &arr,ll inv){
			for(ll i=1,j=0;i<sz;++i){
				ll bit=sz>>1; for(;j&bit;bit>>=1) j^=bit; j^=bit;
				if(i<j) swap(arr[i],arr[j]);
			}
			for(ll l=2;l<=sz;l<<=1){
				ll wlen=inv?root_inv:root;
				for(ll i=l;i<maX;i<<=1) wlen=(wlen*wlen)%mod;
				for(ll i=0;i<sz;i+=l){
					ll w=1;
					for(ll j=0;j<l/2;++j){
						ll x=arr[i+j],y=(w*arr[i+j+l/2])%mod;
						arr[i+j]=(x+y<mod?x+y:x+y-mod);
						arr[i+j+l/2]=(x-y>=0?x-y:x-y+mod);
						w=(w*wlen)%mod;
					}
				}
			}
			if(inv){
				ll n_1=fsp(sz,mod-2);
				forn(i,0,sz){
					arr[i]=(arr[i]*n_1)%mod;
				}
			}
		}
};
constexpr ll MM=1002772198720536577;
//
//g=3
//998244353=119*2^23 + 1 
//g^c=15311432
//inv=469870224
//M1=1004535809
//M1^-1=332747959
//
//1004535809=479*2^21 + 1
//g^c=702606812
//inv=700146880
//M2=998244353
//M2^-1=669690699
ll mul(ll a,ll b){
	__int128 aa=a,bb=b,cc;
	cc=(aa*bb)%MM;
	return (ll)cc;
}
void solve(){
	FFT fft1(998244353,15311432,469870224,1<<23,1004535809,332747959);
	FFT fft2(1004535809,702606812,700146880,1<<21,998244353,669690699);
	//ll x=(fft1.M*fft1.M_inv)%fft1.mod;
	//ll y=(fft2.M*fft2.M_inv)%fft2.mod;
	//err(x,y);
	ll n,m;
	cin >> n >> m;
	vc<ll> a(n+1),b(m+1);
	for(auto &v:a) cin >> v;
	for(auto &v:b) cin >> v;
	ll sz=1;
	for(;sz<a.size()+b.size();sz<<=1);
	a.resize(sz),b.resize(sz);
	vc<ll> A=a,B=b;
	fft1.fft(sz,a,0);
	fft1.fft(sz,b,0);
	forn(i,0,sz) a[i]=(a[i]*b[i])%fft1.mod;
	fft1.fft(sz,a,1);

	fft2.fft(sz,A,0);
	fft2.fft(sz,B,0);
	forn(i,0,sz) A[i]=(A[i]*B[i])%fft2.mod;
	fft2.fft(sz,A,1);

	forn(i,0,n+m+1) cout << (mul(a[i],fft1.M*fft1.M_inv) + mul(A[i],fft2.M*fft2.M_inv))%MM << " \n"[i==n+m];
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
