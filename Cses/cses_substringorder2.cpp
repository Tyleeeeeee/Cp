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
class state{
    public:
        ll len,cnt,link,next[26];
        
        state(){}
};
ll n,k,sz,dp[mxN<<1]={0};
state t[mxN<<1];
string res;
void sam(const string &s){
    memset(t,0,sizeof(t));
    t[0].link=-1,t[0].cnt=0;
    ll last,cur; last=0;
    for(auto&v:s){
        cur=++sz; 
        t[cur].len=t[last].len+1,t[cur].cnt=1;
        ll p; p=last;
        while(p!=-1 && !t[p].next[v-'a']) t[p].next[v-'a']=cur,p=t[p].link;
        if(p==-1) t[cur].link=0;
        else{
            ll q; q=t[p].next[v-'a'];
            if(t[p].len+1==t[q].len) t[cur].link=q;
            else{
                ll clone; clone=++sz;
                t[clone].len=t[p].len+1,t[clone].cnt=0,t[clone].link=t[q].link;
                memcpy(t[clone].next,t[q].next,sizeof(t[q].next));
                while(p!=-1 && t[p].next[v-'a']==q) t[p].next[v-'a']=clone,p=t[p].link;
                t[q].link=t[cur].link=clone;
            }
        }
        last=cur;
    }
}
void dfs_cnt(){
    vc<ll> adj[n+1];
    forn(i,1,sz+1) adj[t[i].len].emp(i);
    forr(i,n,1){
        for(auto&v:adj[i]){
            t[t[v].link].cnt+=t[v].cnt;
        }        
    }
}
ll dfs_dp(ll u=0){
    if(dp[u]) return dp[u];
    forn(i,0,26){
        if(t[u].next[i]){
            dp[u]+=dfs_dp(t[u].next[i]);
        }
    }
    return dp[u]+=t[u].cnt;
}
void dfs(ll u=0){
    if(k<=t[u].cnt) return;
    else k-=t[u].cnt;
    forn(i,0,26){
        if(!t[u].next[i]) continue;
        ll v; v=t[u].next[i];
        if(k>dp[v]) k-=dp[v];
        else {
            res+=char(i+'a');
            return dfs(v);
        }
    }
}
void solve(istream &cin){
    string s;
    cin>>s>>k;
    n=s.length(),sz=0;
    sam(s);
    dfs_cnt();
    t[0].cnt=0;
    dfs_dp();
    dfs();
    cout << res << '\n';
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
