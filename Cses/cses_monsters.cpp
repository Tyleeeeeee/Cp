 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/
//Happy new year 2025
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
#include<queue>
#include<stack>
using namespace std;
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
ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
constexpr ll mxN=1e3+1;
constexpr ll m2xN=mxN*mxN;
ll n,m,si,sj,f,r,d[mxN][mxN],vs[mxN][mxN]={0};
vc<pll> q(m2xN);
string s[mxN],res;
bool ok(ll x,ll y){return x>=0&&x<n&&y>=0&&y<m&&!vs[x][y]&&s[x][y]=='.';}
void bfs(){
    while(f!=r){
        auto [x,y]=q[f=(f+1)%m2xN];
        forn(i,0,4){
            if(s[x+dx[i]][y+dy[i]]=='.' && (d[x][y]+1 < d[x+dx[i]][y+dy[i]]))
                d[x+dx[i]][y+dy[i]]=d[x][y]+1;
            // err(x,y,x+dx[i],y+dy[i],n,m,ok(x+dx[i],y+dy[i]));
            if(!ok(x+dx[i],y+dy[i])) continue;
            vs[x+dx[i]][y+dy[i]]=1;
            q[r=(r+1)%m2xN]={x+dx[i],y+dy[i]};
        }
    }
}
void dfs(ll i,ll j,ll ds){
    s[i][j]='#';
    if(i==0 || j==0 || i==(n-1) || j==(m-1)){
        cout << "YES" << '\n' << res.length() << '\n' << res << '\n';
        exit(0);
    }
    if(i>0 && s[i-1][j]=='.' && d[i-1][j]>ds+1) res+='U',dfs(i-1,j,ds+1),res.pop_back();
    if(i<n && s[i+1][j]=='.' && d[i+1][j]>ds+1) res+='D',dfs(i+1,j,ds+1),res.pop_back();
    if(j>0 && s[i][j-1]=='.' && d[i][j-1]>ds+1) res+='L',dfs(i,j-1,ds+1),res.pop_back();
    if(j<m && s[i][j+1]=='.' && d[i][j+1]>ds+1) res+='R',dfs(i,j+1,ds+1),res.pop_back();
    s[i][j]='.';
}
void solve(istream &cin){
    cin>>n>>m;
    f=r=0;
    memset(d,0x3f,sizeof(d));
    forn(i,0,n){
        cin>>s[i];
        forn(j,0,m){
            if(s[i][j]=='M') d[i][j]=0,q[r=(r+1)%m2xN]={i,j},vs[i][j]=1; 
            if(s[i][j]=='A') si=i,sj=j,s[i][j]='.';
        }
    }
    bfs();
    // forn(i,0,n)forn(j,0,m){err(i,j,d[i][j]);}
    dfs(si,sj,0);
    cout << "NO" << '\n';
}
int main()
{
    // ifstream cin("input.txt");
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}

