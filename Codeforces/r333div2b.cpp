#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,pr,cr;
    cin>>n;
    int arr[n-1];
    for(int q=0;q<n;++q){
        cin>>cr;
        if(q>0){
            arr[q-1]=cr-pr;
        }
        pr=cr;
    }
    int ans,l,pre,cur,zrcnt;
    ans=l=zrcnt=pre=0;
    for(int rp=0;rp<n-1;++rp){
        cur=arr[rp],l++;
        zrcnt+=(cur==0);
        if(cur*pre==1){
            //no zero between cur and pre l=1 else l=zero+1
            l=zrcnt+1;
        }
        if(cur) zrcnt=0;
        if(cur) pre=cur;
        ans=l+1>ans?l+1:ans;
    }
    cout << ans << "\n";
}

