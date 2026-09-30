#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    int t,n,arr[26],ans;
    string s;
    cin>>t;
    while(t--&&cin>>n>>s)
    {
       ans=0;
       memset(arr,0,sizeof(arr)) ;
       for(int q=0;q<n;++q)
       {
           if(!arr[s[q]-'a'])
           {
               arr[s[q]-'a']=1;
               ans+=n-q;
           }
       }
       cout << ans << "\n";
    }
}

