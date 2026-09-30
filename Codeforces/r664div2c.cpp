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
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,m,res;
int main()
{
    fast_io;
    cin>>n>>m;
    ll a[n],b[m]; 
    for(auto&v:a)cin>>v; for(auto&v:b)cin>>v;
    ll ok,cnt;
    ok=res=0;
    for(res=0;res<(1<<9) && !ok;){
        for(int q=0;q<n;++q){
            cnt=0;
            for(int w=0;w<m;++w) cnt+=(((a[q]&b[w])|res)==res);
            if(!cnt) break;
        }
        if(cnt) ok=1;
        else ++res;
    }
    cout << res << "\n";
}
/*
   author :tlx
               */





