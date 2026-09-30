#include<iostream>
using namespace std;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);

    int n,a,b;
    cin>>n;
    a=b=0;
    if(n%3==2) b++;
    b+=n/3;
    a+=b/12,b%=12;
    cout << a << " " << b << "\n";
}

