#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void permute(vector<string> &ans,string &s,int l,int r)
{
    if(l==r)
    {
        if(!ans.size()) ans.push_back(s);
        else if(find(ans.begin(),ans.end(),s)==ans.end()) ans.push_back(s);
        return ;
    }
    else{
        for(int i=l;i<=r;++i)
        {
            s.insert(l,1,s[i]);
            s.erase(i+1,1);
            permute(ans,s,l+1,r);
            s.insert(i+1,1,s[l]);
            s.erase(l,1);
        }
    }
}
int main()
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            string s;
            vector<string> ans;
            cin >> s;
            sort(s.begin(),s.end(),[](char a,char b){if(toupper(a)!=toupper(b))return toupper(a)<toupper(b);else return a<b;});
            permute(ans,s,0,s.length()-1);
            for(int i=0;i<ans.size();++i)
            {
                cout << ans[i] << "\n";
            }
        }
    }
    
}


