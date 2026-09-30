#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,n,ans;
    string s,sl1,sl2,sl3,sl4;
    cin>>t;
    while(t--&&cin>>n>>s){ ans=0,sl1=sl3="2",sl2=sl4="0";
        int i,j;
        if((i=s.find(sl1+sl2+sl3+sl4))!=string::npos && (j=s.rfind(sl1+sl2+sl3+sl4))!=string::npos && (!i || j==n-4)) ans=1;
        else if((i=s.find(sl1))!=string::npos && (j=s.rfind(sl2+sl3+sl4))!=string::npos && !i && j==n-3) ans=1;
        else if((i=s.find(sl1+sl2))!=string::npos && (j=s.rfind(sl3+sl4))!=string::npos && !i && j==n-2) ans=1;
        else if((i=s.find(sl1+sl2+sl3))!=string::npos && (j=s.rfind(sl4))!=string::npos && !i && j==n-1) ans=1;
        cout << (ans?"YES":"NO") << "\n";
    }
}

