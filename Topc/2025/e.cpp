#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ar array
#define vc vector
#define emp emplace_back
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)


constexpr ll mxN=5e3+1;
	
ll n,m,k,l,r,mid,g[mxN][mxN]{},vs[mxN][mxN],s,t;
ll u1,v1,u2,v2; 
bool ok(ll x,ll y){
	return 1<=x&&x<=n&&1<=y&&y<=m&&g[x][y]<=mid&&!vs[x][y];
}
void dfs(ll x,ll y){
	vs[x][y]=1;
	//cerr << "dfs: " << x << ' ' << y << ' ' << g[x][y] << '\n';
	//cerr << "check: " << x << ' ' << y+1 << ' ' << (g[x][y+1]<=mid) << ' ' << !vs[x][y+1] << '\n';
	if(g[x][y] && u1<=x && x<=u2 && v1<=y && y<=v2) s++;
	if(!g[x][y] && (u1>x || x>u2 || v1>y || y>v2)) t++;
	if(ok(x-1,y)) dfs(x-1,y);
	if(ok(x+1,y)) dfs(x+1,y);
	if(ok(x,y-1)) dfs(x,y-1);
	if(ok(x,y+1)) dfs(x,y+1);
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	forn(i,1,k+1){ll x,y; cin >> x >> y,g[x][y]=i;}
	cin >> u1 >> v1 >> u2 >> v2;
	l=-1,r=k+1;
	while(r-l>1){
		mid=l+r>>1;
		// cerr << "lrmid: " << l << ' ' << r << ' ' << mid << '\n';
		ll ok=1;
		forn(i,u1,u2+1) forn(j,v1,v2+1) ok&=(g[i][j]<=mid);
		// cerr << "ok: " << ok << '\n';
		if(ok){
			s=t=0;
			memset(vs,0,sizeof(vs));
			dfs(u1,v1);
			// cerr << "st: " << s << ' ' << t << '\n';
			ok&=(s<=t);
		}
		if(ok) r=mid;
		else l=mid;
	}
	cout << (r<k+1?r:-1) << '\n';
	return 0;
}
