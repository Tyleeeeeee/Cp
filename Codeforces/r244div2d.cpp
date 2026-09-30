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
 
constexpr int mxN=2e4+10;
class Node{
	public:
		ll len,link,c1,c2,next[27]{};
		Node(){}
};
ll n,m,sz=0;
Node t[mxN];
void sam(const string &s){
	ll last,cur;
	t[0].len=0,t[0].link=-1,t[0].c1=t[0].c2=0;
	last=0;
	for(auto&v:s){
		ll c; c=(v=='#'?26:v-'a');
		cur=++sz;
		t[cur].len=t[last].len+1,t[cur].c1=(t[cur].len<=n),t[cur].c2=(t[cur].c1^1);
		for(;last!=-1 && !t[last].next[c]; t[last].next[c]=cur,last=t[last].link);
		if(last==-1) t[cur].link=0;
		else{
			ll q; q=t[last].next[c];
			if(t[last].len+1==t[q].len) t[cur].link=q;
			else{
				ll clone; clone=++sz;
				t[clone].len=t[last].len+1,t[clone].link=t[q].link;
				memcpy(t[clone].next,t[q].next,sizeof(t[q].next));
				for(;last!=-1 && t[last].next[c]==q;t[last].next[c]=clone,last=t[last].link);
				t[q].link=t[cur].link=clone;
			}
		}
		last=cur;
	}
}
void solve(istream &cin){
	ll res;
	string s1,s2; cin>>s1>>s2;
	n=s1.length(),s1=s1+"#"+s2,m=s1.length();
	sam(s1);
	vc<ll> a[m+1];
	forn(i,1,sz+1) a[t[i].len].emp(i);
	res=inf;
	forr(i,m,1){
		for(auto&v:a[i]){
			if(t[v].c1==1 && t[v].c2==1) res=min(res,t[t[v].link].len+1);
			t[t[v].link].c1+=t[v].c1,t[t[v].link].c2+=t[v].c2;
		}
	}
	cout << (res<inf?res:-1) << '\n';
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
