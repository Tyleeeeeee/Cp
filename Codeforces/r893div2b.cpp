#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int main()
{
    fast_io;
    ll t,n,m,d;
    cin>>t;
    while(t--&&cin>>n>>m>>d){
        ll k,sum;
        vector<ll> arr(m+2,1),ans;
        sum=1,arr[m+1]=n;
        for(int q=1;q<=m;++q) cin>>arr[q],sum+=(arr[q]!=1);
        for(int q=1;q<m+2;++q){
            if(q<m+1) sum+=(arr[q]-1-arr[q-1])/d;
            else sum+=(arr[q]-arr[q-1])/d;
        }
        for(int q=1;q<m+1;++q){
            ll tmp=sum;
            tmp=tmp-1-(arr[q]-arr[q-1]-1)/d-(arr[q+1]-arr[q]-(q<m))/d;
            tmp+=(arr[q+1]-arr[q-1]-(q<m))/d;
            tmp+=arr[q]==1;
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end()) ;
        ll mn;
        mn=1e18,k=0;
        for(int q=0;q<ans.size();++q){
            mn=min(mn,ans[q]);
            if(ans[q]==mn) k++;
        }
        cout << mn << " " << k << "\n";
    }
}

