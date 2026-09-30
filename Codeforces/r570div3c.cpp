#include<iostream>
using namespace std;


long long t,n,k,a,b,ans;
long long solve(){
    long long i,j,mid,ans;
    ans=i=0,j=k/a<=n?k/a:n;
    while(i<=j){
        mid=(i+j)/2;
        if(mid*a+(n-mid)*b>=k) j=mid-1;
        else{ i=mid+1,ans=mid>ans?mid:ans;}
    }
    return ans;
}
int main()
{
    cin>>t;
    while(t--&&cin>>k>>n>>a>>b){
        if(b*n>=k) ans=-1;
        else ans=solve();
        cout << ans << "\n";
    }
}

