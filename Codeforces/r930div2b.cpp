#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,n,max,min;
    string s[2];
    cin>>t;
    while(t--&&cin>>n) { max=n-1,min=0;
        for(auto&v:s)cin>>v;
        for(int q=n-1;q>0;--q){
            if(s[0][q]=='1' && s[1][q-1]=='0') max=q-1;
        }
        for(int q=0;q<max;++q){
            if(s[0][q+1]=='0' && s[1][q]=='1') min=q+1;
        }
        for(int q=0;q<=max;++q) cout << s[0][q];
        for(int q=max;q<n;++q) cout << s[1][q];
        cout << "\n";
        cout << max-min+1 << "\n";
    }
}

