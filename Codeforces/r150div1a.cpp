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

ll n;
unordered_set<ll> ans;
int main()
{
    fast_io;
    cin>>n;
    ll a[n];
    for(int q=0;q<n;++q){
        cin>>a[q];
        ans.insert(a[q]);
        ll i,j,k;
        i=a[q],j=0,k=q-1;
        while(k>=0){
            if((i|=a[k])==(j|=a[k])) break;
            else ans.insert(i);
            k--;
        }
    }
    cout << ans.size() << "\n";
}
/*
   author :tlx
               */

