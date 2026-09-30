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
 
constexpr ll mxN=1e5+1;

ll dp[mxN],a[mxN];
deque<ll> mx,mn,orz;
void add(ll ind){
    while(!orz.empty() && dp[orz.back()]>=dp[ind]) orz.pop_back();
    orz.push_back(ind);
}
ll query(ll ind){
    while(!orz.empty() && orz.front()<ind) orz.pop_front();
    return orz.empty()?inf:dp[orz.front()];
}
void add_mx(ll ind){
    while(!mx.empty() && a[mx.back()]<=a[ind]) mx.pop_back();
    mx.push_back(ind);
}
ll query_mx(ll ind){
    while(!mx.empty() && mx.front()<ind) mx.pop_front();
    return a[mx.front()];
}
void add_mn(ll ind){
    while(!mn.empty() && a[mn.back()]>=a[ind]) mn.pop_back();
    mn.push_back(ind);
}
ll query_mn(ll ind){
    while(!mn.empty() && mn.front()<ind) mn.pop_front();
    return a[mn.front()];
}
void solve(istream &cin){
    ll n,s,l;
    cin>>n>>s>>l;
    ll lb; lb=1;
    forn(i,1,n+1){
        cin>>a[i];
        if(i-l>=0) add(i-l);
        add_mx(i);
        add_mn(i);
        while(query_mx(lb)-query_mn(lb)>s) lb++;
        dp[i]=query(lb-1)+1;
    }
    cout << (dp[n]>=inf?-1:dp[n]) << '\n';
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
