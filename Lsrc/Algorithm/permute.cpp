#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void permute(string &s,int l,int r)
{
    if(l==r){cout<<s<<"\n"; return;}
    else{
        for(int i=l;i<=r;++i)
        {
            s.insert(l,1,s[i]);
            s.erase(i+1,1);
            permute(s,l+1,r);
            s.insert(i+1,1,s[l]);
            s.erase(l,1);
        }
    }
}
int main()
{
    string s="abcd";
    permute(s,0,s.length()-1);
}


