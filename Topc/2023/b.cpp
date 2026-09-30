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

void solve(){
	ll rt,rj,St,Sj;
	double st,sj;
	cin >> rt >> rj >> st >> sj;
	rt--,rj--;
	St=llround(st*100),Sj=llround(sj*100);
	cout << (rt*Sj<rj*St?"TAOYUAN":rt*Sj>rj*St?"JAKARTA":"SAME") << '\n';
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
