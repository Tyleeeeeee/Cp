#include<iostream>
#include<string>
using namespace std;
using ll=long long;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    int arr[]={1,3,5,4,2};
    string s,af;
    cin>>s;
    for(int q=0;q<5;++q) af.push_back(s[arr[q]-1]);
    ll n,a;
    n=stoi(af),a=n%100000;
    for(int q=0;q<4;++q) a=(a*n)%100000;
    af=!a?"00000":to_string(a);
    cout << af << "\n";
}

