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
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,resm,m,v,resl,a[10],pref[100000][10];
string s;
int main()
{
    fast_io;
    auto gcd=[](ll a,ll b){if(!b)return a; while(a%=b)swap(a,b); return b;};
    auto lcm=[&gcd](ll a,ll b){return a*b/gcd(a,b);};
    cin>>t;
    while(t--&&cin>>m>>s){
        ll lccm,lm;
        resm=resl=0;
        memset(a,0,sizeof(a));
        memset(pref,0,sizeof(pref));
        for(int q=0;q<s.length();++q){
            a[s[q]-'0']++;
            pref[q][s[q]-'0']++;
            for(int w=0;w<10;++w) pref[q][w]+=q>0?pref[q-1][w]:0;
        }
        lccm=1,lm=0;
        for(int q=0;q<10;++q) if(a[q]) lccm=lcm(lccm,q);
        for(int q=0;q<10;++q) if(a[q]) lm+=lccm/q;
        for(ll q=lm;q<=s.length();q+=lm){
            for(ll w=0;w+lm-1<s.length();++w){
                ll ok=1;
                for(ll i=1;i<10 && ok;++i) if(a[i] && lccm/i*(q/lm)!=(pref[w+lm-1][i]-(w>0?pref[w-1][i]:0))) ok=0;
                if(ok){
                    ll sum=0;
                    for(ll i=w;i<=w+lm-1;++i) sum=((sum*10)+s[i]-'0')%m;
                    resm=max(resm,sum),resl=max(resl,q);
                }
            }
        }
        cout << resl << " " << resm << "\n";
    }
}
/*
   author :tlx
               */



