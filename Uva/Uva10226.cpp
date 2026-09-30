#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n,sum;
    string s;
    cin >> n;
    cin.get();
    cin.get();
    while(n--)
    {
        sum=0;
        map<string,double> mp;
        while(getline(cin,s) && !s.empty())
        {
           if(mp.find(s)==mp.end()) mp[s]=1;
           else mp[s]++;
           sum++;
        }
        for(auto &q:mp)
        {
            q.second/=sum;
            q.second*=100;
        }
        // sort(mp.begin(),mp.end(),[](string &a,string &b){return a<b;});
        for(auto &q:mp)
        {
            cout << fixed << setprecision(4) << q.first << " " << q.second << "\n";
        }
        cout << "\n";
    }
}

