#include<iostream>
using namespace std;

int main()
{
    int n,m,ans;
    cin>>n>>m;
    ans=0;
    while(n && m && (n>1 || m>1)){
        ans++;
        if(n>m)m--,n-=2;
        else n--,m-=2;
    }
    cout << ans << "\n";
}

