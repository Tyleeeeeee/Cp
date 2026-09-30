#include<iostream>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int dp[1000];
int findsub(string &s1,string &s2)
{
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(int q=1;q<s2.length();++q){
        if(s2[q]==s2[dp[q-1]]) dp[q]=dp[q-1]+1;
        else{
            int x=dp[q-1]-1,ok;
            ok=1;
            while(x>=0 && ok){
                if(s2[q]==s2[dp[x]]) dp[q]=dp[x]+1,ok=0;
                else x=dp[x]-1;
            }
            if(ok) dp[q]=0;
        }
    }
    int i,j;
    i=j=0;
    while(i<s1.length() && j<s2.length()){
        if(s1[i]==s2[j]) i++,j++;
        else if(!j) i++;
        else j=dp[j-1];
    }
    //j==s2.length() i-j
    return (j==s2.length()?i-j:-1);
}
int main()
{
    fast_io;
    string s1="ababaaabcde",s2="abcz";
    cout << findsub(s1,s2) << "\n";
}

