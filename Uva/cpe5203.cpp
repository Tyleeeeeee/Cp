#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
    map<char,vector<int> > mp={{'M',{1,0,0}},{'Y',{0,1,0}},{'C',{0,0,1}},{'R',{1,1,0}},{'V',{1,0,1}},{'G',{0,1,1}},{'B',{1,1,1}}};
    int t,st;
    while(cin >> t)
    {
    while(t--)
    {
        st=1;
        string s;
        vector<int> ans(3);
        for(int i=0;i<3;++i) cin>>ans[i];
        cin >> s;
        for(int i=0;i<s.length();++i)
        {
            if(mp.find(s[i])!=mp.end())
            {
                transform(mp[s[i]].begin(),mp[s[i]].end(),ans.begin(),ans.begin(),[](int a,int b){return b-a;});
                for(int q:ans){if(q<0){st=0; break;}}
                if(!st) break;
            }
        }
        if(st)
        {
            cout << "YES";
            for(int q:ans) cout << " " << q;
            cout << "\n";
        }
        else cout << "NO\n";
    }
    }
}

