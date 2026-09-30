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
 
ll fsp(ll a,ll b){
	ll ans; ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mdl1;
		a=(a*a)%mdl1,b>>=1;
	}
	return ans;
}
void solve(istream &cin){
	ll n,len[10],val[10];
	string s;
	cin>>s>>n;
	vc<pr<ll,string>> q(n);
	for(auto&[d,t]:q){
		cin>>d>>t;
		string tmp;
		forn(i,2,t.length()) tmp+=t[i];
		swap(t,tmp);
	}
	forn(i,0,10) val[i]=i,len[i]=1;
	forr(i,n-1,0){
		auto &[d,t]=q[i];
		ll tmpv,tmpl;
		tmpv=tmpl=0;
		forr(j,t.length()-1,0){
			tmpv=(tmpv+val[t[j]-'0']*fsp(10,tmpl))%mdl1;
			tmpl=(tmpl+len[t[j]-'0'])%(mdl1-1);
		}
		val[d]=tmpv%mdl1,len[d]=tmpl%(mdl1-1);
	}
	// forn(i,0,10){err(i,val[i],len[i]);}
	ll res,cur; cur=res=0;
	forr(i,s.length()-1,0){
		// err(i,s[i],cur);
		res=(res+val[s[i]-'0']*fsp(10,cur))%mdl1,cur=(cur+len[s[i]-'0'])%(mdl1-1);
	}
	cout << res%mdl1 << '\n';
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
