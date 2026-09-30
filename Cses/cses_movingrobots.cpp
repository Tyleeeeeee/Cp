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
ll dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
//0=L 1=LD 2=D 3=RD 4=R 5=RU 6=U 7=LU
// ll dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};

constexpr ll mxN=1e2+1;

ll k;
double dp[mxN][9][9],a[9][9];
bool ok(ll i,ll j,ll dir){return i+dx[dir]>=1&&i+dx[dir]<=8&&j+dy[dir]>=1&&j+dy[dir]<=8;}
void solve(istream &cin){
    cin>>k;
    double res; res=0;
    forn(i,1,9) forn(j,1,9) a[i][j]=1;
    forn(x,1,9){
        forn(y,1,9){
            memset(dp,0,sizeof(dp));
            dp[0][x][y]=1;
            forn(m,0,k){
                forn(i,1,9){
                    forn(j,1,9){
                        double d; d=0;
                        forn(dir,0,4) if(ok(i,j,dir)) d++;
                        forn(dir,0,4){
                            if(ok(i,j,dir)) dp[m+1][i+dx[dir]][j+dy[dir]]+=dp[m][i][j]/d;
                        }
                    }
                }
            }
            forn(i,1,9) forn(j,1,9) a[i][j]*=(1-dp[k][i][j]);
        }
    }
    forn(i,1,9) forn(j,1,9) res+=a[i][j];
    cout << fixed << setprecision(6) << res << '\n';
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
