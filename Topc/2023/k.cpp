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

constexpr ll mxN=5e6+10;
ll z[mxN]{};
string s;
void zf(){
	ll l,r=-1;
	forn(i,1,s.length()){
		if(r>i) z[i]=min(r-i,z[i-l]);
		while(i+z[i]<s.length() && s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]>r) l=i,r=i+z[i];
	}
}
void solve(){
	cin >> s;
	s="kick#"+s;
	zf();
	ll res=0;
	forn(i,5,s.length()) res+=(z[i]==4);
	cout << res << '\n';
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
