#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int t,n,k,arr[26],old,evn;
void solve()
{
    int i,j,mid,mold,mevn,ans;
    ans=0,i=1,j=n/k;
    while(i<=j){
        mid=(i+j)/2;
        if(mid%2) mold=k,mevn=k*(mid-1)/2;
        else mevn=(mid/2)*k,mold=0;
        if(evn<mevn || (evn>=mevn && (evn-mevn)*2+old < mold)) j=mid-1;
        else ans=max(ans,mid),i=mid+1;
    }
    cout << ans << "\n";
}
int main()
{
    string s;
    cin>>t;
    while(t--&&cin>>n>>k>>s){
        old=evn=0;
        memset(arr,0,sizeof(arr));
        for(int q=0;q<s.length();++q){
            arr[s[q]-'a']++;
        }
        for(int q=0;q<26;++q){
            if(arr[q]%2) old++,evn+=(arr[q]-1)/2;
            else evn+=arr[q]/2;
        }
        solve();
    }
}

