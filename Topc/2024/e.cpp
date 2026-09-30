#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define DEBUG 1
   #if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
       template<typename T,typename... Args>
       inline void debug (const T& val,const Args&... args){
           cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
       }
       #define terr cerr << "I am here" << '\n'
   #endif
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back

//l[0]=r[0]=-d l[n+1]=r[n+1]=m+1
//a[i]=l[i]-(r[i-1]+d)-1 b[i]=l[i+1]-(r[i]+d)-1
//c=x+2d-(l[i+1]-r[i]-1)
//1 i,i+1
//2 i-1,i+2
//..
//k i-k+1 i+k
constexpr ll inf=1e18;
constexpr ll mxN=2e3+10;
ll n,m,d,x,l[mxN],r[mxN],a[mxN];
void solve(){
	cin >> n >> m >> d >> x;
	a[0]=a[n+2]=0;
	l[0]=r[0]=-d,l[n+1]=r[n+1]=m+1+d;
	forn(i,1,n+1) cin >> l[i] >> r[i];
	forn(i,1,n+2) a[i]=l[i]-(r[i-1]+d)-1;
	ll res=inf;
	forn(i,0,n+1){
		ll c=max(0LL,x+d-a[i+1]);
		if(!c){res=min(res,0LL); break;}
		else{
			ll k,cost,box;
			for(k=1,cost=box=0;box<c && (i-k+1>0 || i+k<n+1);k++){
				if(box+a[max(0LL,i-k+1)]+a[min(n+2,i+k+1)]>=c){cost+=k*(c-box),box=c;}
				else box+=a[max(0LL,i-k+1)]+a[min(n+2,i+k+1)],cost+=k*(a[max(0LL,i-k+1)]+a[min(n+2,i+k+1)]);
			}
			if(box==c) res=min(res,cost);
		}
	}
	cout << (res<inf?res:-1) << '\n';
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	int testcase;
	testcase=1;
	//cin >> testcase;
	while(testcase--) solve();
	return 0;
}
