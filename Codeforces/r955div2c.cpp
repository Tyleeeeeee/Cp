#include<iostream>
using namespace std;

int main()
{
    int t;
    long long n,l,r,cur,ans,val,lp,rp;
    cin>>t;
    while(t--&&cin>>n>>l>>r){ ans=cur=0;
            long long arr[n];
            for(auto&v:arr)cin>>v;
            for(lp=rp=0;rp<n;++rp)
            {
               cur+=arr[rp];
               if(arr[rp]>r){cur=0,lp=(rp+1);continue;}
               if((arr[rp]>=l && arr[rp]<=r)){ans++,cur=0,lp=(rp+1);}
               while(cur>r && lp<=rp){
                   cur-=arr[lp++];
               }
               if((cur>=l && cur<=r)){
                   ans++,cur=0,lp=(rp+1);
               }
            }
            cout << ans << "\n";
        }
}



