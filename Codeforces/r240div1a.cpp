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

ll n,k,res;
vector<ll> ans;
int main()
{
    fast_io;
    cin>>n>>k;
    res=0;
    if(n/2 > k || (n==1 && k>0)) res=-1;
    else{
        if(n==1) ans.push_back(1);
        else{
            ll x;
            x=k-(n-2)/2;
            ans.push_back(x),ans.push_back(2*x);
            for(ll q=2*x+1;q<=1e9 && ans.size()<n;++q){
                ans.push_back(q);
            }
        }
    }
    if(res!=-1) for(auto&v:ans) cout << v << " ";
    else cout << res ;
    cout << "\n";
}

