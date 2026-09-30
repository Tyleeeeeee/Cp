spgrague grundy的一些性質就是說本質上來說sg number是一個level of winning state 我們定義0為losing state即0級是losing state 那麼sg number的定義為s狀態可以抵達的所有狀態的mex值 那麼我們可以得知s狀態的sg number其實代表了其所在的level它可以去到底下的任何level 例如mex(0,1)=2說明其是一個2級winning state 它可以轉換成0級或者1級 這邊注意mex(0,1,3,4)=2 為什麼s狀態不變成3級還是4級呢？答案很直觀0級意味著losing 而越高級別的winning state 可以轉變到更多的winning state 換句話說就是擁有更多的優勢 那麼作為對手若是執行最優解的話 絕對不會讓你佔據優勢 也就是說你一旦升級 對手會馬上跟你降級 那麼根據impartial game的其中一個定義為優先次數 即不會陷入無限迴圈 那麼最終你必然無法升級 只能降級 通過這個觀察 我們發現到對於很多遊戲其實可以將其分解為multiple pile即每一個pile有對應的sg number 那麼這個問題會退化成nim game 也就是每一輪玩家可以選擇其中一個pile 進行降級相當於拿走石頭 那麼最終答案即為xor sum =0 losing 反之winning
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
 
void solve(istream &cin){
    ll n,sum;
    cin>>n;
    sum=0;
    forn(i,1,n+1){
        ll x; cin>>x;
        sum^=x;
    }
    cout << (sum?"first":"second") << '\n';
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

