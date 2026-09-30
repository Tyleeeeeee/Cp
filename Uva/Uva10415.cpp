#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    map<char,vector<int> > mp;
    mp['c']={0,1,1,1,0,0,1,1,1,1}; mp['C']={0,0,1,0,0,0,0,0,0,0};
    mp['d']={0,1,1,1,0,0,1,1,1,0}; mp['D']={1,1,1,1,0,0,1,1,1,0};
    mp['e']={0,1,1,1,0,0,1,1,0,0}; mp['E']={1,1,1,1,0,0,1,1,0,0};
    mp['f']={0,1,1,1,0,0,1,0,0,0}; mp['F']={1,1,1,1,0,0,1,0,0,0};
    mp['g']={0,1,1,1,0,0,0,0,0,0}; mp['G']={1,1,1,1,0,0,0,0,0,0};
    mp['a']={0,1,1,0,0,0,0,0,0,0}; mp['A']={1,1,1,0,0,0,0,0,0,0};
    mp['b']={0,1,0,0,0,0,0,0,0,0}; mp['B']={1,1,0,0,0,0,0,0,0,0};
    
    string s;
    int t;
    auto check=[](int a,int b){if(a==1 && b==0) return 1; return 0;};
    auto renew=[](int a){return a;};
    auto add=[](int a,int b){return a+b;};
    while(cin>>t)
    {
        cin.get();
        while(t-- && getline(cin,s))
        {
            vector<int> ans(10,0),bf(10,0);
            for(int i=0;i<s.length();++i)
            {
               transform(mp[s[i]].begin(),mp[s[i]].end(),bf.begin(),bf.begin(),check);
               transform(ans.begin(),ans.end(),bf.begin(),ans.begin(),add);
               transform(mp[s[i]].begin(),mp[s[i]].end(),bf.begin(),renew);
            }
            for(int i=0;i<10;++i)
            {
                if(!i) cout<<ans[i];
                else cout<<" "<<ans[i];
            }
            cout<<"\n";
        }
    }
}

