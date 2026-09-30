#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    int n;
    string s;
    map<string,int> mp;
    cin>>n;
    for(int q=0;q<n;++q){
        cin>>s;
        if(mp.find(s)==mp.end()){mp[s]=1; cout << "OK";} 
        else {cout << s << mp[s]++;}
        cout << "\n";
    }
}


