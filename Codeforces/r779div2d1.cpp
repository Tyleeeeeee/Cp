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

ll t,l,r,res,a[0x20000],cnt[32][2];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>l>>r){
        ll sum,b;
        b=sum=0;
        for(int q=0;q<=r;++q) cin>>a[q],sum^=a[q],b^=q;
        if((r-l+1)&1) res=sum^b;
        else{
            memset(cnt,0,sizeof(cnt));
            for(int q=0;q<=r;++q){
                for(int w=0;w<32;++w){
                    cnt[w][a[q]&1]++,a[q]>>=1;
                }
            }
            res=0;
            for(int q=0;q<32;++q) res|=(cnt[q][0]<cnt[q][1]?(1<<q):0);
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

