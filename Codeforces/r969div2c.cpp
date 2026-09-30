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

ll t,n,a,b,res;
ll arr[100000];
int main()
{
    fast_io;
    auto gcd=[](ll a,ll b){
        while(a%=b) swap(a,b);
        return b;
    };
    cin>>t;
    while(t--&&cin>>n>>a>>b){
        ll d=gcd(a,b);
        for(int q=0;q<n;++q)cin>>arr[q],arr[q]%=d;
        sort(arr,arr+n);
        res=arr[n-1]-arr[0];//smallest possible range for front count
        for(int q=0;q<n-1;++q){
            //count back
            res=min(res,arr[q]+d-arr[q+1]);
        }
        cout << res << "\n";
    }
}

