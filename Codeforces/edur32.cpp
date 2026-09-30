#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string s;
int ans[26],arr[26];
int solve(int n)
{
    int i,j,mid,fans;
    i=1,j=n,fans=1e8;
    while(i<=j){
        mid=(i+j)/2;
        int lp,rp,ok;
        ok=lp=rp=0;
        for(;rp<n;++rp){
            arr[s[rp]-'a']++;
            while(rp-lp+1==mid){
                for(int q=0;q<26;++q) ans[q]+=(arr[q]>0);
                arr[s[lp++]-'a']--;
            }
        }
        for(int q=0;q<26;++q) if(ans[q]==n-mid+1) ok=1;
        memset(ans,0,sizeof(ans));
        memset(arr,0,sizeof(arr));
        if(ok){j=mid-1,fans=fans>mid?mid:fans;} 
        else i=mid+1;
    }
    return fans;
}

int main()
{
    cin>>s;
    memset(ans,0,sizeof(ans));
    memset(arr,0,sizeof(arr));
    cout << solve(s.length()) << "\n";
}

