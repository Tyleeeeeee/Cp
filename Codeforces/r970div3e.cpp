#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t,n,ans;
    string s;
    cin>>t;
    while(t--&&cin>>n>>s){
        if(n<=3) ans=n%2;
        else{
            if(n%2){
                ans=1e8;
                int f[2][26],b[2][26];
                memset(f,0,sizeof(f)),memset(b,0,sizeof(b));
                for(int q=n-1;q>=0;--q) b[q%2][s[q]-'a']++;
                for(int q=0;q<n;++q){
                    b[q%2][s[q]-'a']--;
                    int mx,lft;
                    lft=n;
                    for(int k=0;k<2;++k){
                        mx=0;
                        for(int j=0;j<26;++j){
                            mx=max(mx,b[1-k][j]+f[k][j]);
                        }
                        lft-=mx;
                    }
                    ans=min(ans,lft);
                    f[q%2][s[q]-'a']++;
                }
            }
            else{
                int mx,arr[26];
                ans=n;
                for(int k=0;k<2;++k){
                    mx=0;
                    memset(arr,0,sizeof(arr));
                    for(int q=0;q<n;++q) if(q%2==k) arr[s[q]-'a']++;
                    for(int q=0;q<26;++q) mx=max(mx,arr[q]);
                    ans-=mx;
                }
            }
        }
        cout << ans << "\n";
    }
}

