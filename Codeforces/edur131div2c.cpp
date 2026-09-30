#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int t,n,m,arr[200001];

int solve()
{
    long long i,j,mid,sum,ans=1e8;
    sum=0,i=1,j=2*m;
    while(i<=j){ sum=0;
        mid=(i+j)/2;
        for(int q=1;q<=n;++q){
            if(mid>=arr[q]) sum+=arr[q]+floor((mid-arr[q])/2);
            else sum+=mid;
        }
        if(sum<m) i=mid+1;
        else {ans=ans>mid?mid:ans; j=mid-1;}
    }
    return ans;
}
int main()
{
    int tmp;
    cin>>t;
    while(t--&&cin>>n>>m){
        memset(arr,0,sizeof(arr));
        for(int q=1;q<=m;++q)cin>>tmp,arr[tmp]++;
        cout << solve() << "\n";
    }
}

