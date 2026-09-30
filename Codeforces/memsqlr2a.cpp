#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int n,res,arr[26];
string s,ans;
int solve()
{
    int i,j,mid,sum,ans;
    ans=1e8,i=1,j=1000;
    while(i<=j){
        sum=0;
        mid=(i+j)/2;
        for(int q=0;q<26;++q)sum+=ceil((double)arr[q]/mid);
        if(sum>n) i=mid+1;
        else j=mid-1,ans=min(ans,mid);
    }
    if(ans==1e8) ans=-1;
    return ans;
}
int main()
{
    fast_io;
    cin>>s>>n;
    memset(arr,0,sizeof(arr));
    for(int q=0;q<s.length();++q) arr[s[q]-'a']++;
    res=solve();
    if(res!=-1){
        for(int q=0;q<26;++q){
            if(arr[q]) for(int w=0;w<ceil((double)arr[q]/res);++w) ans.push_back(q+'a');
        }
        while(ans.size()<n) ans.push_back('a');
    }
    cout << res << "\n";
    if(res!=-1) cout << ans << "\n";
}

