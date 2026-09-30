#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    string s;
    cin>>t;
    while(t--&&cin>>s){
        vector<int> ans;
        for(string sc:{"twone","one","two"}){
            int i=s.find(sc,0);
            //no need always find from 0 you can start from last time i
            for(;i!=string::npos;){
                s[i+sc.length()/2]='?';
                ans.push_back(i+sc.length()/2 + 1);
                i=s.find(sc,i);
            }
        }
        cout << ans.size() << "\n";
        for(auto&v:ans)cout << v << " " ;
        cout << "\n";
    }
}

