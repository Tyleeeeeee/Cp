#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    string a("1"),b("1"),tmp;
    auto align=[](string &a,string &b)
    {
        if(a.length()<b.length()){a.insert(0,b.length()-a.length(),'0');}
        if(b.length()<a.length()){b.insert(0,a.length()-b.length(),'0');}
    };
    auto add=[&tmp](string &a,string &b)
    {
        int sum;
        int sd;
        int carry=0;
        for(int i=a.length()-1;i>=0;--i)
        {
            tmp.insert(0,1,((a[i]-'0')+(b[i]-'0')+carry)%10+'0');
            carry=((a[i]-'0')+(b[i]-'0')+carry)/10;
        }
        if(carry) tmp.insert(0,1,carry+'0');
        a=b;
        b=tmp;
        tmp.clear();
    };
    while(cin >> N)
    {
        cout << "The Fibonacci number for " << N << " is ";
        if(!N) cout << 0 << "\n";
        else{
            for(int i=0;i<N-2;++i)
            {
                align(a,b);
                add(a,b);
            }
            cout << b << "\n";
        }
    }
}

