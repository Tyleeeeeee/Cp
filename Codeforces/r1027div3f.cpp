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

constexpr ll mxN=1e6+1;
ll mp[mxN]{},x,y,k,res;
vc<pll> solve(ll x){
	vc<pll> ans;
	while(x>1){
		ll p,cnt; p=mp[x],cnt=0;
		while(x%p==0) x/=p,cnt++;
		ans.emp(pll{p,cnt});
	}
	sort(all(ans));
	return ans;
}
ll cal(ll x){
	vc<ll> div;
	for(ll i=1;i*i<=x;++i){
		if(x%i==0){
			div.emp(i);
			if(i*i<x) div.emp(x/i);
		}
	}
	sort(all(div));
	vc<ll> dp(div.size(),inf);
	dp[0]=0;
	forn(i,1,div.size()){
		forn(j,0,i){
			if(div[i]%div[j]==0 && div[i]/div[j]<=k) dp[i]=min(dp[i],dp[j]+1);
		}
	}
	return dp[div.size()-1]<inf?dp[div.size()-1]:-1;
}
ll fsp(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?ans*a:ans),a*=a,m>>=1); return ans;}
void solve(istream &cin){
	cin>>x>>y>>k;
	vc<pll> f1,f2;
	f1=solve(x),f2=solve(y);
	ll i,j,I,J;
	for(i=j=0,I=J=1;i<f1.size() && j<f2.size();){
		if(f1[i].fr==f2[j].fr){
			if(f1[i].sc>f2[j].sc) J*=fsp(f1[i].fr,f1[i].sc-f2[j].sc);
			else if(f1[i].sc<f2[j].sc) I*=fsp(f1[i].fr,f2[j].sc-f1[i].sc);
			i++,j++;
		}
		else if(f1[i].fr>f2[j].fr) I*=fsp(f2[j].fr,f2[j].sc),j++;
		else J*=fsp(f1[i].fr,f1[i].sc),i++;
	}
	while(i<f1.size()) J*=fsp(f1[i].fr,f1[i].sc),i++;
	while(j<f2.size()) I*=fsp(f2[j].fr,f2[j].sc),j++;
	ll ansI,ansJ; ansI=cal(I),ansJ=cal(J);
	cout << (ansI==-1 || ansJ==-1?-1:ansI+ansJ) << '\n';;
}
 
int main()
{
	forn(i,2,mxN){
		if(!mp[i]){
			mp[i]=i;
			for(ll j=i*i;j<mxN;j+=i) mp[j]=i;
		}
	}
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
