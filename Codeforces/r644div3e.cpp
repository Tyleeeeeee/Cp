#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,n,ans,a,b;
    cin>>t;
    while(t--&&cin>>n){string s[n]; ans=1;
        for(auto&v:s)cin>>v;
        for(int q=0;q<n;++q){
            for(int w=0;w<n;++w){ a=b=1;
                if(s[q][w]=='1'){
                    if(q<n-1 && s[q+1][w]!='1') a=0;
                    if(w<n-1 && s[q][w+1]!='1') b=0;
                    if(!(a||b)){ans=0; break;}
                }
            }
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}

