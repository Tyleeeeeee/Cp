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

int n,k,arr[2];
string s;
int solve()
{
    int i,j,mid,ans;
    ans=0,i=1,j=s.length();
    while(i<=j){
        mid=(i+j)/2;
        int lp,rp,ok;
        //0 a 1 b
        ok=0;
        memset(arr,0,sizeof(arr));
        for(lp=rp=0;rp<s.length() && !ok;++rp){
            arr[s[rp]-'a']++;
            while(rp-lp+1==mid){
                if(mid-max(arr[0],arr[1])<=k) ok=1;
                arr[s[lp++]-'a']--;
            }
        }
        if(ok){ans=max(ans,mid),i=mid+1;}
        else j=mid-1;
    }
    return ans;
}
int main()
{
    fast_io;
    cin>>n>>k>>s;
    cout << solve() << "\n";
}

