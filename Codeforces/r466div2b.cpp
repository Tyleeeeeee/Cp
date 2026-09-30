#include<iostream>
using namespace std;

int main()
{
    long long x,n,k,A,B,ans;
    cin>>n>>k>>A>>B;
    x=n;
    ans=0;
    if(x!=1){
        if(k>x || k==1){ ans=(x-1)*A;}
        else{
        if(x%k){
            long long tmp=x/k;
            ans+=(x-tmp*k)*A;
            x=tmp*k;
        }
        while(x!=1){
            if(x%k) x--,ans+=A;
            else if((x-x/k)*A > B) ans+=B,x/=k;
            else ans+=(x-x/k)*A,x/=k;
        }
    }
    }
    cout << ans << "\n";
}

