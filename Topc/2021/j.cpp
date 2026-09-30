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
#define all(x) x.begin(),x.end()
using i128=__int128;

//10010103 200
//1001003 100
//1000100 100
//10001000 100
constexpr ll inf=0x3f3f3f3f3f3f3f3f;

void solve(){
	string x,y;
	cin >> x >> y;
	ll X,Y;
	for(ll i=0,cur=0;i<x.length();i++){
		ll c=x[i]-'0';
		if(c>=0 && c<10) cur=c+cur*10;
		else {X=-1; break;}
		if(i==x.length()-1) X=cur;
	}
	for(ll i=0,cur=0;i<y.length();i++){
		ll c=y[i]-'0';
		if(c>=0 && c<10) cur=c+cur*10;
		else {Y=-1; break;}
		if(i==y.length()-1) Y=cur;
	}
	if(X!=-1 && Y!=-1) cout << (X-Y) << '\n';
	else cout << "NaN" << '\n';
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
