#include<iostream>
#include<cstring>
using namespace std;

long long n,qe;
long long dp[2][200000];
long long solve(long long qe,long long &sm)
{
    int i,j,mid;
    long long ans;
    sm-=qe;
    if(sm<=0) ans=n;
    else{
        i=0,j=n-1;
        while(i<=j){
            mid=(i+j)/2;
            if(dp[0][mid]>=sm) i=mid+1;
            else j=mid-1;
        }
        ans=n-j;
    } 
    return ans;
}

int main()
{
    memset(dp,0,sizeof(dp));
    cin>>n>>qe;
    for(int q=0;q<n;++q)cin>>dp[0][q];
    for(int q=0;q<qe;++q)cin>>dp[1][q];
    for(int q=n-2;q>=0;--q)
        dp[0][q]+=dp[0][q+1];
    for(long long q=0,tmp=dp[0][0];q<qe;++q){
        tmp=(tmp<=0?dp[0][0]:tmp);
        cout << solve(dp[1][q],tmp) << "\n"; 
    }
}


