#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    int N;
    string s;
    string bs="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    while(cin>>s)
    {
        N=2;
        for(int i=0;i<s.length();++i)
        {
            if(!ispunct(s[i])) if(bs.find(s[i])+1>N) N=bs.find(s[i])+1;
        }
        while(N<63) 
        {
            int ans=0;
            for(int i=0;i<s.length();++i)
            {
                if(!ispunct(s[i]))
                {
                    ans=(ans*N + bs.find(s[i]))%(N-1);
                }
            }
            if(!ans) break;
            else N++;
        }
        if(N<63) cout << N << "\n";
        else cout << "such number is impossible!\n";
    }
}


