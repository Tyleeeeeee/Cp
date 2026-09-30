#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int t,st[3],l,r,min;
    string s;
    cin>>t;
    while(t--&&cin>>s)
    {
        l=0;
        min=0x16161616;
        memset(st,0,sizeof(st));
        for(r=0;r<s.length();++r)
        {
            st[s[r]-'1']++;
            while(st[0]>0 && st[1]>0 && st[2]>0){
                min=min<r-l+1?min:r-l+1;
                st[s[l++]-'1']--;
            }
        }
        if(min>200000) min=0;
        cout << min << "\n";
    }
}

