#include<iostream>
#include<string>
using namespace std;

long long mdl=1e9+7;

int main()
{
    long long dp[100001],ans,a,b;
    dp[0]=dp[1]=1;
    for(int q=2;q<100001;++q){
        dp[q]=(dp[q-1]+dp[q-2])%mdl;
    }
    string s;
    cin>>s;
    ans=1;
    a=b=0;
    for(int q=0;q<s.length();++q){
        if(s[q]=='w' || s[q]=='m'){ans=0; break;}
        else{
            if(s[q]=='u') a++;
            else if(a) ans=(ans*dp[a])%mdl,a=0;
            if(s[q]=='n') b++;
            else if(b) ans=(ans*dp[b])%mdl,b=0;
        }
    }
    if(a||b){
        if(a) ans=(ans*dp[a])%mdl;
        if(b) ans=(ans*dp[b])%mdl;
    }
    cout << ans << "\n";
}

