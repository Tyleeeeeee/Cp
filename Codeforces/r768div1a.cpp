#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,k;
vector<ll> ans;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>k){
        ans.clear();
        for(int q=0;q<n;++q) ans.push_back(q);
        if(k<n-1) swap(ans[0],ans[k]);
        else swap(ans[0],ans[n-2]),swap(ans[1],ans[2]);
        if(k==n-1 && n<8) cout << -1 << "\n";
        else for(int q=0;q<n/2;++q) cout << ans[q] << " " << ans[n-q-1] << "\n";
    }
}

