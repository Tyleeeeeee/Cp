#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    int c,t,bf,d,m,ans;
    string s;
    while(cin >> t)
    {
        c=0;
        while(t-- && cin >> bf)
        {
            ans=2;
            map<string,int> mp;
            for(int i=0;i<bf;++i)
            {
                cin >> s >> d;
                getchar();
                mp[s]=d;
            }
            cin >> bf ;
            cin >> s;
            if(mp.find(s)==mp.end()) ans=0;
            else if(mp[s]<=bf) ans=2;
            else if(mp[s]<=bf+5) ans=1;
            else ans=0;
            cout << "Case " << ++c << ": ";
            if(!ans) cout << "Do your own homework!\n";
            else if(ans==1) cout << "Late\n";
            else cout << "Yesss\n";
        }
    }
}