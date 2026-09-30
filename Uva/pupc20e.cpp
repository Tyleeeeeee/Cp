#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int arr[62],min,fl;
    string s;
    while(cin>>s && s.length()>1){ min=0x16161616,fl=0;
        memset(arr,0,sizeof(arr));
        for(int q=0;q<s.length()-1;++q){
            if(s[q]>='a' && s[q]<='z') arr[s[q]-'a']++;
            else if(s[q]>='A' && s[q]<='Z') arr[s[q]-'A'+26]++;
            else if(s[q]>='0' && s[q]<='9') arr[s[q]-'0'+52]++;
        }
        for(const auto&v:arr) min=(v && min>v)?v:min;
        for(int q=0;q<s.length()-1;++q){
            if(s[q]>='a' && s[q]<='z' && arr[s[q]-'a']==min) {cout << (fl?" ":"")<<s[q];arr[s[q]-'a']=0,fl=1;}
            else if(s[q]>='A' && s[q]<='Z' && arr[s[q]-'A'+26]==min){ cout << (fl?" ":"")<<s[q]; arr[s[q]-'A'+26]=0,fl=1;}
            else if(s[q]>='0' && s[q]<='9' && arr[s[q]-'0'+52]==min){ cout << (fl?" ":"")<<s[q]; arr[s[q]-'0'+52]=0,fl=1;}
            else continue;
        }
        cout << "\n";
    }
    
    cout << "\n";
}

