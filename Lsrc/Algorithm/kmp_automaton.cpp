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

constexpr ll mxN=105;
ll n,m,nex[mxN][26]{},k[mxN]{},dp[1005][mxN][2]{};
string s;
void kmp(){
	forn(i,1,m){
		ll j; j=k[i-1];
		while(j>0 && s[j]!=s[i]) j=k[j-1];
		if(s[j]==s[i]) k[i]=j+1;
	}
}
void solve(istream &cin){
	cin>>n>>s;
	m=s.length();
	kmp();
	//forn(i,0,m){err(i,k[i]);}
	forn(i,0,m+1){
		forn(j,0,26){
			if(i>0 && (s[i]-'A')!=j) nex[i][j]=nex[k[i-1]][j];
			else nex[i][j]=i+(s[i]-'A'==j);
		}
	}
	// forn(i,0,m+1){forn(j,0,26){err(i,j,nex[i][j]);}}
	dp[0][0][0]=1;
	forn(i,0,n){
		forn(f,0,2){
			forn(j,0,m+1){
				forn(c,0,26){
					// err(i,j,c,nex[j][c],dp[i][j]);
					ll nf; nf=f|(nex[j][c]==m);
					dp[i+1][nex[j][c]][nf]=(dp[i+1][nex[j][c]][nf]+dp[i][j][f])%mdl1;
				}
			}
		}
	}
	ll res; res=0;
	forn(i,0,m+1) res=(res+dp[n][i][1])%mdl1;
	cout << res << '\n';
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

