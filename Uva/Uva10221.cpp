#include<iostream>
#include<numbers>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    const int r=6440;
    int s;
    string unit;
    double ang,ans1,ans2;
    while(cin >> s >> ang >> unit)
    {
        if(unit=="min") ang/=60;
        while(ang>360) ang/=360;
        if(ang>180) ang=360-ang;
        ang=ang/360*2*numbers::pi;
        ans1=numbers::pi*2*(r+s)*ang/(2*numbers::pi);
        ans2=sqrt(2*pow(s+r,2)*(1-cos(ang)));
        cout << fixed << setprecision(6) << ans1 << " " << ans2 << "\n";
    }
}

