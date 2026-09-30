#include<iostream>
using namespace std;

int main()
{
    int a,b,st=1,ans=1;
    cin>>a>>b;
    if(a==1 && b==1) st=0;
    while(!(a<=2 && b<=2))
    {
        if(a<=2) a++,b-=2;
        else if(b<=2) b++,a-=2;
        else a-=2,b++;
        ans++;
    }
    cout << (st?ans:0) << "\n";
}

