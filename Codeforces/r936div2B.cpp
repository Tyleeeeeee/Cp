#include<iostream>
#include<algorithm>
using namespace std;

#define mod(x,y) (((x%y)+y)%y)
long long mm=1e9+7;
void solve(long long sum,long long Msb,int k)
{
    //sum+2^k*Msb % mm
    long long ref=2,ans=Msb;
    while(k)
    {
        if(k%2) ans*=ref;
        ref*=ref;
        k/=2;
        ans=mod(ans,mm);
        ref=mod(ref,mm);
    }
    ans=mod((ans+sum),mm);
    cout << ans << "\n";
}
int main()
{
    int t,n,k;
    long long Msb,cur,sum,tmp;
    cin>>t;
    while(t--&&cin>>n>>k)
    {
        Msb=cur=sum=0;
        for(int q=0;q<n;++q)
        {
            cin>>tmp;
            sum+=tmp;
            cur+=tmp;
            cur=max(cur,0LL);// LL refer to long long,F(float),L(double)
            Msb=max(Msb,cur);
        }
        sum-=Msb;
        solve(sum,Msb,k);
    }
}

