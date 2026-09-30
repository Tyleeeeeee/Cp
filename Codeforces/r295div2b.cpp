#include<iostream>
using namespace std;

int main()
{
    int n,m,ans;
    cin>>n>>m;
    ans=0;
    while(m>n){
        ans++;
        if(m%2==0)m/=2;
        else m++;
    }
    ans+=n-m;
    cout << ans << "\n";
}

