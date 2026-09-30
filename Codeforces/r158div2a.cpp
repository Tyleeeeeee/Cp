#include<iostream>
#include<string>
using namespace std;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);

    int a,b,n;
    string s;
    cin>>s>>b>>n;
    int sum;
    a=stoi(s),sum=a;
    while(n--){
        sum*=10,sum%=b;
        if((b-sum)<10 || (b-sum)==b) s.push_back((b-sum<10?b-sum:0)+'0'),sum+=(b-sum)%b;
        else break;
    }
    cout << (n==-1?s:"-1") << "\n";
}

