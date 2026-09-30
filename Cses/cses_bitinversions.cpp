#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
using namespace std;
using ll=long long;
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define lwb lower_bound
#define upb upper_bound
#define bg begin
#define ed end
#define all(x) x.bg(),x.ed()
#define vc vector
 
constexpr ll mxN=2e5+1;
class Node{
	public:
		ll f,l,r,mx;
		Node(){}
		Node(ll F,ll L,ll R,ll MX):f(F),l(L),r(R),mx(MX){}
		friend Node operator+(const Node &a,const Node &b){
			return {a.f&&b.f&&(a.l*b.l>0),!a.f?a.l:a.l*b.l>0?a.l+b.l:a.l,
					!b.f?b.r:b.r*a.r>0?b.r+a.r:b.r,
					max({a.mx,b.mx,a.r*b.l>0?abs(a.r+b.l):0})};
		}
};
ll n,m;
Node t[mxN<<1];
string s;
void built(){forr(i,n-1,1) t[i]=t[i<<1]+t[i<<1|1];}
void pst(ll p){p+=n-1; ll v; v=t[p].l; for(t[p]={1,v<0?1:-1,v<0?1:-1,1};(p>>=1);)t[p]=t[p<<1]+t[p<<1|1];}
Node query(ll l,ll r){ 
	Node pfx(-1,-1,-1,-1),sfx(-1,-1,-1,-1);
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1) pfx=(pfx.f==-1?t[l++]:pfx+t[l++]);
		if(!(r&1)) sfx=(sfx.f==-1?t[r--]:t[r--]+sfx);
	}
	//cerr << pfx.f << ' ' << pfx.l << ' ' << pfx.r << ' ' << pfx.mx << '\n';
	//cerr << sfx.f << ' ' << sfx.l << ' ' << sfx.r << ' ' << sfx.mx << '\n';
	return pfx+sfx;
}
void solve(istream&cin){
	cin>>s>>m;
	n=s.length();
	forn(i,0,n) t[i+n]={1,s[i]=='0'?-1:1,s[i]=='0'?-1:1,1};
	built();
	forn(i,1,m+1){
		ll x; cin>>x;
		pst(x);
		//forn(j,1,2*n){cerr << "j:" << j  << ' '<< t[j].f << ' ' << t[j].l << ' ' <<t[j].r << ' '<< t[j].mx << '\n';}
		cout << query(1,n).mx << " \n"[i==m];
	}
}
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	//ifstream cin("input.txt");
	solve(cin);
	return 0;
}
