#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define log(x,y) (log(y)/log(x))

ll n,k;
ll solve()
{
    ll i,j,mid,ans;
    ans=1e18,i=1,j=n;
    while(i<=j){
        mid=(i+j)/2;
        ll sum,ky,tmp;
        sum=tmp=mid;
        ky=ceil((double)log(k,mid));
        while(ky--) sum+=(tmp/=k);
        if(sum>=n) ans=min(ans,mid),j=mid-1;
        else i=mid+1;
    }
    return ans;
}
int main()
{
    fast_io;
    cin>>n>>k;
    cout << solve() << "\n";
}

