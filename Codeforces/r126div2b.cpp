#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n,tmp;
    double sum=0;
    cin>>n;
    for(int q=0;q<n;++q) cin>>tmp,sum+=tmp;
    cout << setprecision(12) << sum/n << "\n";
}

