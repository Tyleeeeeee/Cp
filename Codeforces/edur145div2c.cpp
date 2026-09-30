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
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>k){
        vector<ll> res; 
        for(ll q=1;q<=n;++q){
            if(k>=q) res.push_back(2),k-=q;
            else if(k>0) res.push_back(-2*(q-k)+1),k=0;
            else res.push_back(-1000);
        }
        for(auto&v:res)cout << v << " ";
        cout << "\n";
    }
}

