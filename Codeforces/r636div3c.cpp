#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    long long tmp,pre,ans;
    cin>>t;
    while(t--&&cin>>n)
    {
        ans=0;
        for(int q=0;q<n;++q)
        {
            cin>>tmp;
            if(!q) pre=tmp;
            else if(pre*tmp<0){
                ans+=pre;
                pre=tmp;
            }
            else if(pre*tmp>0){
                pre=max(pre,tmp);
            }
        }
        ans+=pre;
        cout << ans << "\n";
    }
}

