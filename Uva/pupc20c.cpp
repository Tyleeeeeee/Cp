#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;

int main()
{
    int t;
    string s,ds,pres,curs;
    cin>>t;
    cin.get();
    while(t-- && cin >> s >> ds)
    {
        curs=pres="";
        map<string,char> mp;
        for(int q=0;q<s.length();++q)
        {
            if(isdigit(s[q])){curs+=s[q]; continue;} 
            if(pres!="")
            {
               int i=pres.rfind('0') ;
               pres.erase(i,s.length());
               curs=pres+=curs;
               mp[curs]=s[q];
               pres=curs;
               curs.clear();
            }
            else{ mp[curs]=s[q]; pres=curs; curs.clear();}
        }
        curs.clear();
        for(int q=0;q<ds.length();++q)
        {
            curs+=ds[q];
            if(mp.find(curs)!=mp.end()){ cout << mp[curs]; curs.clear();}
        }
        cout << "\n";
    }
}

