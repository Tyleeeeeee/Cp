#include<iostream>
using namespace std;

int main()
{
    int n,ref,ans;
    while(cin >> n)
    {
        ans=0;
        ref=1;
        while(ref%n)
        {
            ref%=n;
            ref=(ref*10)+1;
            ans++;
        }
        cout << ++ans << "\n";
    }
}
