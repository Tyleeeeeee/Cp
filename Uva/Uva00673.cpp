#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int t,c,r;
    char ch;
    string s;
    while(cin >> t)
    {
        cin.get();
        while(t-- && getline(cin,s))
        {
            c=0;
            if(s.length()%2) cout << "No\n";
            else if(!s.length()) cout << "Yes\n";
            else{
                for(int i=1;i<s.length();++i)
                {
                    if(s[i]==')' && s[i-1]=='('){s[i]=s[i-1]='1'; c++;}
                    if(s[i]==']' && s[i-1]=='['){s[i]=s[i-1]='1'; c++;}
                }
                if(!c) cout << "No\n";
                else{
                   ch='-';
                   for(int i=0;i<s.length();++i)
                   {
                        if(s[i]=='1') continue;
                        else{
                                if((ch=='(' && s[i]==')') || (ch=='[' && s[i]==']'))
                                {
                                    s[i]='1';
                                    s[r]='1';
                                    i=0;
                                }
                                ch=s[i]; r=i;
                        }
                   }
                   cout << (count(s.begin(),s.end(),'1')==s.length()?"Yes\n":"No\n");
                }
            }
        }
    }
}

