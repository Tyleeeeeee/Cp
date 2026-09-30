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
 
ll n,q;
void query2(ll x,ll N,ll r=0,ll c=0){
    if(N==1){
        if(x==1) r++,c++;
        else if(x==2) r+=2,c+=2;
        else if(x==3) r+=2,c++;
        else if(x==4) r++,c+=2;
        cout << r << ' ' << c << '\n';
        return ;
    }
    ll k; k=(x+(1LL<<(2*N-2))-1)/(1LL<<(2*N-2));
    // err(k,1LL<<(2*N-2));
    if(k>1) x-=(k-1)*(1LL<<(2*N-2));
    if(k==2||k==3) r+=(1LL<<(N-1));
    if(k==2||k==4) c+=(1LL<<(N-1));
    query2(x,N-1,r,c);
    // query2(x-(k>0)?(k-1)*(1LL<<N):0,N-1,r+(k==2||k==3?(1LL<<(N-1)):0),c+(k==2||k==4?(1LL<<(N-1)):0));
    return;
}
void query1(ll x,ll y,ll N,ll s=0){
    if(N==1){
        s+=(x==1 && y==1?1:x==1 && y==2?4:x==2 && y==1?3:2);
        cout << s << '\n';
        return ;
    }
    ll k; k=1LL<<(N-1);
    if(x<=k && y>k) s+=3*(k*k);
    else if(x>k && y<=k) s+=2*(k*k);
    else if(x>k && y>k) s+=(k*k);
    if(x>k) x-=k;
    if(y>k) y-=k;
    query1(x,y,N-1,s);
    // query1(x-(x<=k)?0:k,y-(y<=k)?0:k,N-1,s+(x<=k && y<=k ? 0 : x<=k && y>k ? 3*k : x>k && y<=k ? 2*k : k));
    return ;
}
void solve(istream &cin){
    cin>>n>>q;
    while(q--){
        char c; cin>>c>>c;
        if(c=='>'){
            ll x,y; cin>>x>>y;
            query1(x,y,n);
        }
        else{
            ll x; cin>>x;
            query2(x,n);
        }
    }
}
 
int main()
{
    fast_io;
    // ifstream cin("input.txt");
    ll testcase;
    cin>>testcase;
    // testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
