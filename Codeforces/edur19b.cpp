#include<iostream>
using namespace std;

int main()
{
    int n,sc,sum,mx,mi,ans;
    cin>>n;
    sum=ans=sc=0,mx=-1e4-1,mi=1e4+1;
    int arr[n];
    for(auto&v:arr)cin>>v,sum+=v>0?v:0,sc+=v<0?1:0,mi=v>0&&v<mi&&v%2?v:mi,mx=v<0&&v>mx&&v%2?v:mx;
    if(sc==n) ans=mx;
    else if(sum%2) ans=sum;
    else ans=(sum-=mi<mx*-1?mi:mx*-1);
    cout << ans << "\n";
}

