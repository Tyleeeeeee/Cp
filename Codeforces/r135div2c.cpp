#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAXXX 100001 //1e5+1
#define MAXX 1000000001 //1e9+1
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll n,k,res,ans1,ans2;
string s;
int main()
{
    fast_io;
    cin>>n>>k>>s;
    ans1=ans2=res=0;
    if(k>2){
        for(int q=1;q<s.length();++q){
            char c;
            if(s[q]==s[q-1]){
                for(c='A';c<='A'+k-1;++c) if(c!=s[q-1] && (q+1<s.length()?(c!=s[q+1]):1)) break;
                s[q]=c,res++;
            }
        }
        cout << res << "\n" << s << "\n";
    }
    else{
        ll st;
        st=1;
        for(int q=0;q<s.length();++q){
            if(st) ans1+=(s[q]=='B'),ans2+=(s[q]=='A');
            else ans1+=(s[q]=='A'),ans2+=(s[q]=='B');
            s[q]=(!(q&1)?'A':'B');
            st^=1;
        }
        cout << (ans1<ans2?ans1:ans2) << "\n";
        if(ans1<ans2) cout << s ;
        else for(int q=0;q<s.length();++q) cout << (q&1?'A':'B') ;
        cout << "\n";
    }
}

 /*--------------\
/   author :tlx   \
\      Tylee      /
 \--------------*/

