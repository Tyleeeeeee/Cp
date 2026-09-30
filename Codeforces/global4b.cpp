#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    long long ww,O,ans;
    cin>>s;
    ww=O=ans=0;
    for(int q=0;q<s.length();++q){
        if(s[q]=='o'){
            O+=ww;
        }
        else if(q>0 && s[q-1]=='v'){
            ww++;
            ans+=O;
        }
    }
    cout << ans << "\n";
}

