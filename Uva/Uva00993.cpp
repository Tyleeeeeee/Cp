#include<iostream>
#include<functional>
using namespace std;

int main()
{
    int t,N;
    function<int(int)> solve=[&solve](int N)
    {
        if(N>=0 && N<10) return N;
        for(int i=9;i>1;--i)
        {
            if(N%i==0 && solve(N/i)!=-1) return 10*solve(N/i)+i;
        }
        return -1;
    };
    while(cin >> t)
    {
        while(t-- && cin >> N)
        {
            cout << solve(N) << "\n";
        }
    }
}

