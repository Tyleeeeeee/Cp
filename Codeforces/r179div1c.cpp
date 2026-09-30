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

ll n,m,a[51],dp1[51][51][2],dp2[51][51][2],C[51][51]{};
ll mul(ll x,ll y,ll z){
	return (((x*y)%mdl1)*z)%mdl1;
}
void solve(istream &cin){
	forn(i,0,51) C[i][0]=1;
	forn(i,1,51){
		forn(j,1,i+1){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mdl1;
		}
	}
	cin >> n >> m,m/=50;
	ll c1=0,c2=0,c;
	forn(i,1,n+1) cin >> a[i],a[i]/=50,c1+=(a[i]==1),c2+=(a[i]==2);
	if(!m || (m==1 && c1>1) || (m==1 && c2) || (m==2 && c2 && c1<2)) {cout << -1 << '\n' << '0' << '\n'; return;}
	memset(dp1,0x3f,sizeof(dp1)),memset(dp2,0,sizeof(dp2));
	dp1[c1][c2][0]=0,dp2[c1][c2][0]=1;
	for(c=0;;c++){
		forn(i,0,c1+1){
			forn(j,0,c2+1){
				if(c&1^1){
					forn(k,0,i+1){
						forn(l,0,j+1){
							if(k+2*l<=m && k+l>0){
								if(dp1[i][j][c&1]+1<dp1[i-k][j-l][c&1^1]){
									dp1[i-k][j-l][c&1^1]=dp1[i][j][c&1]+1;
									dp2[i-k][j-l][c&1^1]=(dp2[i-k][j-l][c&1^1]+mul(dp2[i][j][c&1],C[i][k],C[j][l]))%mdl1;
								}
								else if(dp1[i][j][c&1]+1==dp1[i-k][j-l][c&1^1])
									dp2[i-k][j-l][c&1^1]=(dp2[i-k][j-l][c&1^1]+mul(dp2[i][j][c&1],C[i][k],C[j][l]))%mdl1;
							}
						}
					}
				}
				else{
					forn(k,0,c1-i+1){
						forn(l,0,c2-j+1){
							if(k+2*l<=m && k+l>0){
								if(dp1[i][j][c&1]+1<dp1[i+k][j+l][c&1^1]){
									dp1[i+k][j+l][c&1^1]=dp1[i][j][c&1]+1;
									dp2[i+k][j+l][c&1^1]=(dp2[i+k][j+l][c&1^1]+mul(dp2[i][j][c&1],C[c1-i][k],C[c2-j][l]))%mdl1;
								}
								else if(dp1[i][j][c&1]+1==dp1[i+k][j+l][c&1^1])
									dp2[i+k][j+l][c&1^1]=(dp2[i+k][j+l][c&1^1]+mul(dp2[i][j][c&1],C[c1-i][k],C[c2-j][l]))%mdl1;
							}
						}
					}
				}
			}
		}
		if(dp1[0][0][1]<INF) break;
	}
	cout << dp1[0][0][1] << '\n' << dp2[0][0][1] << '\n';
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
