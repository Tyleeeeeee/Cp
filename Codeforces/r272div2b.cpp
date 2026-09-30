#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;

double solve(int n,int i)
{
    if(n==i) return 1;
    if(i==0) return 1;
    return solve(n-1,i)+solve(n-1,i-1);
}
int main()
{
    string s1,s2;
    int i1,j1,i2,j2;
    double ans=0;
    cin>>s1>>s2;
    i1=j1=i2=j2=0;
    for(int q=0;q<s1.length();++q) {
        if(s1[q]=='+') i1++;
        else if(s1[q]=='-') j1++;
        if(s2[q]=='+') i2++;
        else if(s2[q]=='-') j2++;
    }
    if(s2.find('?')==string::npos) ans=(i1==i2&&j1==j2?1:0);
    else{
        if(i2>i1 || j2>j1)ans=0;
        else{
            ans=solve(i1-i2+j1-j2,i1-i2)*pow(0.5,i1-i2+j1-j2);
        }
    }
    cout << setprecision(12) << ans << "\n";
}

