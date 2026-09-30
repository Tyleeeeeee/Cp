#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int mx=0,lb;
    string s;
    vector<string> vc;
    while(getline(cin,s))
    {
        vc.push_back(s);
        mx=s.length()>mx?s.length():mx;
    }
    for(int i=0;i<mx;++i)
    {
        lb=0;
        while(i>=vc[lb].length()) lb++;
        for(int j=vc.size()-1;j>=lb;--j)
        {
            if(vc[j].size()>i)cout << vc[j][i] ;
            else cout << " ";
        }
        cout << "\n";
    }
}

