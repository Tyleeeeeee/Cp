#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,ans,arr[26];
    string s;
    cin>>n>>s;
    ans=0;
    memset(arr,0,sizeof(arr));
    for(int q=0;q+1<n;++q){
        if(q==n-2){
            if(s[q]==s[q+1]){
                arr[s[q+1]-'A']++;
                if(!arr['R'-'A']) s[q+1]='R';
                else if(!arr['G'-'A']) s[q+1]='G';
                else s[q+1]='B';
                ans++;
            }
            memset(arr,0,sizeof(arr));
        }
        else{
            if(s[q]==s[q+1]){
                arr[s[q+1]-'A']++,arr[s[q+2]-'A']++;
                if(!arr['R'-'A']) s[q+1]='R';
                else if(!arr['G'-'A']) s[q+1]='G';
                else s[q+1]='B';
                ans++;
            }
            memset(arr,0,sizeof(arr));
        }
    }
    cout << ans << "\n" << s << "\n";
}

