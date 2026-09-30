#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,tmp,mn,mnW,ans;
    cin>>t;
    while(t--&&cin>>n){  ans=0,mn=mnW=1e7;
        while(n--){
            cin>>tmp;
            if(mn<tmp && mnW>tmp){
                ans++;
                mnW=tmp;
            }
            mn=min(mn,tmp);
        }
        cout << ans << "\n";
    }
}

