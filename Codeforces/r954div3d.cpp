#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long ;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t,n,ans;
    string s;
    cin>>t;
    while(t--&&cin>>n>>s){ ans=1e18;
        if(n==2) ans=stoi(s);
        else{
            int i=s.find('0');
            if(i!=string::npos && n!=3){
                if(n!=3 || (n==3 && i==0 && i==2)) ans=0;
            }
            else{
                for(int q=1;q<n;++q){
                    char c,p;
                    c=s[q],p=s[q-1];
                    s[q]=s[q-1]='?';
                    ll sum=10*(p-'0')+(c-'0');
                    for(int q=0;q<n;++q){
                       if(s[q]=='?') continue;
                       else if(s[q]=='1' || s[q]=='0'|| sum==1) sum*=(s[q]-'0');
                       else sum+=(s[q]-'0');
                    }
                    ans=min(ans,sum);
                    s[q]=c,s[q-1]=p;
                }
            }
        }
        cout << ans << "\n";
    }
}

