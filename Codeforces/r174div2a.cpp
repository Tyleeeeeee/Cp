#include<iostream>
#include<cstring>
using namespace std;

int p,dp[2000],ans;
int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    cin>>p;
    ans=0;
    for(int x=1;x<p;++x){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int q=1;q<p;++q){
            dp[q]=(dp[q-1]*x)%p;
        }
        int ok;
        ok=1;
        if((dp[p-1]-1)%p!=0) ok=0;
        else{
            for(int q=p-2;q;--q) if((dp[q]-1)%p==0) ok=0;
        }
        ans+=ok;
    }
    cout << ans << "\n";
}

