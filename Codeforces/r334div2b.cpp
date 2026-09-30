#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k,ans;
    cin>>n>>k;
    int arr[n];
    for(auto&v:arr)cin>>v;
    ans=arr[n-1];
    if(n>k){
        //2k-n in solo in box
        //n-(2k-n)=2(n-k)
        //0 2(n-k)-(0+1)
        //1 2(n-k)-(1+1)
        //(n-k)-1 2(n-k)-(n-k-1)=(n-k)
        for(int q=0;q<=n-k-1;++q){
            ans=max(ans,arr[q]+arr[2*(n-k)-(q+1)]);
        }
    }
    cout << ans << "\n";
}

