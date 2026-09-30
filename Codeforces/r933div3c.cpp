#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,n,ans;
    string s;
    cin>>t;
    while(t--&&cin>>n>>s){ ans=0;
        for(string ft:{"mapie","map","pie"}){
            for(int q=0;(q=s.find(ft,q))!=string::npos;){
                s[q+ft.length()/2]='?';
                ans++;
            }
        }
        cout << ans << "\n";
    }
}


