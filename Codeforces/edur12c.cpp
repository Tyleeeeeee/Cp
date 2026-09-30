#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int q=1;q<s.length();++q){ char c='a';
        while(c==s[q-1]||c==s[(q==s.length()-1?q:q+1)]) c++;
        if(s[q-1]==s[q]) s[q]=c;
    }
    cout << s << "\n";
}

