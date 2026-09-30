#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int m,s;
    string mx,mn;
    mx=mn="-1";
    cin>>m>>s;
    if(1<=s && s<=9*m){
        mx.clear(),mn.clear();
        int tmp=s;
        char c;
        c=tmp>9?'9':tmp+'0';
        while(mx.length()!=m){
            mx.push_back(c);
            tmp-=c-'0';
            if(tmp<9) c=tmp+'0';
        }
        tmp=s,c=tmp>9?'9':m==1?tmp+'0':tmp-1+'0';
        while(mn.length()!=m){
           mn.push_back(c);
           tmp-=c-'0';
           if(tmp<=9 && mn.length()==m-1) c=tmp+'0';
           else if(tmp<=9) c=tmp-1+'0';
        }
        if(mn[mn.length()-1]!='0')reverse(mn.begin(),mn.end());
    }
    else if(!s && m==1) mn=mx="0";
    cout << mn << " " << mx << "\n";
}

