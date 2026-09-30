#include<iostream>
#include<utility>
using namespace std;

int main()
{
    int a=30,b=42;
    if(a<b) swap(a,b);
    while(a%=b) swap(a,b);
    cout << b << "\n";
}

