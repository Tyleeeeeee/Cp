#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>
#include<map>
using namespace std;

void solve(string s,map<string,int> &mp)
{
    string wd;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<s.length();++i)
    {
        if(isalpha(s[i])) wd.push_back(s[i]);
        else {
            if(mp.find(wd)!=mp.end()) mp[wd]++;
            else mp[wd]=1;
            wd.clear();
        }
    }
    if(!wd.empty())
    {
        if(mp.find(wd)!=mp.end()) mp[wd]++;
        else mp[wd]=1;
    }
}

int main()
{
    int n,sta;
    string s;
    while(cin >> n)
    {
        sta=0;
        map<string,int> mp;
        while(cin >> s && s!="EndOfText")
        {
            solve(s,mp);    
        }
        for(auto q:mp)
        {
            if(q.second==n) {sta=1; cout << q.first << "\n";}
        }
        if(!sta) cout << "There is no such word.\n";
        cout << "\n";
    }
}

