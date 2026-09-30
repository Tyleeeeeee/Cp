#include<iostream>
#include<cmath>
using namespace std;

long long dgs(long long N)
{
    long long ans=0;
    while(N){
        ans+=N%10;
        N/=10;
    }
    return ans;
}
long long solve(long long N)
{
    long long j,mid,ans,x;
    ans=1e18;
    j=81;
    while(j--){
        mid=j;
        x=(sqrt(mid*mid+4*N)-mid)/2;
        if((sqrt(mid*mid+4*N)-mid)/2-x==0 && dgs(x)==mid){ans=ans>x?x:ans;}
    }
    if(ans==1000000000000000000)  ans=-1;
    return ans;
}
int main()
{
    long long N;
    //N<=1e18 x^2+s(x)x-n=0 -> x^2<x^2+s(x)x=n ->x^2<n -> x<1e9 -> 0<s(x)<=81
    cin>>N;
    cout << solve(N) << "\n";
}

