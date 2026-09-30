#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t,n,q,l,r,dp[200001];
    cin>>t;
    while(t--&&cin>>n){ int cur,pre; dp[1]=-1;
        for(int w=0;w<n;++w){
            cin>>cur;
            if(w){
                if(cur==pre) dp[w+1]=dp[w];
                else dp[w+1]=w;
            }
            pre=cur;
        }
        cin>>q;
        for(int w=0;w<q;++w){
            cin>>l>>r;
            if(dp[r]<l)cout<<-1<<" "<<-1;
            else cout<<r<<" "<<dp[r];
            cout<<"\n";
        }
        cout << "\n";
    }
}

