#include<iostream>
using namespace std;

int main()
{
    int ans;
    cin >> ans;
    ans=(ans%5+5)%5;
    //a%b=a-(a/b)*b
    //-a%b=-a-(-a/b)*b
    //(-a/b)*b >= -a  ((-a/b)-1)*b < -a
    //-a=b*((-a/b)-1)+r
    //-a=(-a/b)*b - b + r
    //-a=-a - (-a%b)-b+r 
    //r=-a%b+b
    //r=(a%b+b)%b
    cout << (-8%5) << "\n";
    cout << ans << "\n";
}

