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
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,ans1,ans2;
string s;
int main()
{
    fast_io;
    //? f=0 01=1
    //? 1=0 0f=1
    cin>>n;
    s="??????????";
    ll x;
    char c;
    for(int q=0;q<n;++q){
        cin>>c>>x;
        for(int q=9;q>=0;--q){
            switch(c){
                case '&':
                    if(!(x&1)) s[q]='0';
                    break;
                case '|':
                    if(x&1) s[q]='1';
                    break;
                case '^':
                    if(x&1){
                        if(s[q]=='?') s[q]='f';
                        else if(s[q]=='f') s[q]='?';
                        else if(s[q]=='0') s[q]='1';
                        else s[q]='0';
                    }
                    break;
            }
            x>>=1;
        }
    }
    //? f=0 01=1
    //? 1=0 0f=1
    ans1=ans2=0;
    for(int q=0;q<=9;++q){
        ans1=(ans1<<1)+(s[q]=='?'||s[q]=='f'?0:1);
        ans2=(ans2<<1)+(s[q]=='?'||s[q]=='1'?0:1);
    }
    cout << 2 << "\n| " << ans1 << "\n" << "^ " << ans2 << "\n";
}
/*
   author :tlx
               */

