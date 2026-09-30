#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define mdl (1000000007)
long long solve(int n,int k)
{
    long long ans=1,a=n;
    while(k){
        if(k%2) ans=(ans*a)%mdl;
        a=(a*a)%mdl;
        k/=2;
    }
    return ans;
}
int main()
{
    int t,n;
    long long ans,k,d;
    cin>>t;
    while(t--&&cin>>n){int arr[2][n],dp[n+1],vs[n+1]; ans=k=d=0;
        memset(vs,0,sizeof(vs));
        for(int q=0;q<2;++q){
            for(int w=0;w<n;++w){
                cin>>arr[q][w];
                if(q) dp[arr[q][w]]=arr[q-1][w];
            }
        }
        for(int q=0;q<n;++q){ int tmp;
            if(dp[arr[0][q]]==arr[1][q] && arr[0][q]!=dp[arr[0][q]]) k++;
            else{
            tmp=arr[0][q];
            while(!vs[tmp] && tmp!=arr[1][q]){vs[tmp]=1,tmp=dp[tmp];}
            if(tmp==arr[1][q]) d++;
            }
        }
        ans=(n-k?solve(2,k/2 + d):solve(2,k/2));
        ans%=mdl;
        cout << ans << "\n";
    }
}

