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

ll t,n,b[MAXXX],res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        res=0;
        vector<ll> pref(n+2,0),surf(n+2,-1e8);
        for(int q=1;q<=n;++q) cin>>b[q];
        for(int q=1;q<=n;++q){
            pref[q]=max(pref[q-1],b[q]+q);
            surf[n-q+1]=max(surf[n-q+2],b[n-q+1]-(n-q+1));
        }
        for(int q=2;q<n;++q) res=max(res,pref[q-1]+b[q]+surf[q+1]);
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

