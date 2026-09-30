#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,min;
    string s;
    cin>>t;
    while(t--&&cin>>s){ min=0x16161616;
        for(auto c:{'0','5'}){
            int i=s.rfind(c);
            if(i!=string::npos && i>0){
                if(c=='0'){
                for(auto ch:{'0','5'}){
                    int j=s.rfind(ch,i-1);
                    if(j!=string::npos)min=min>s.length()-j-2?s.length()-j-2:min;
                }
              }
                else{
                    for(auto ch:{'2','7'}){
                    int j=s.rfind(ch,i-1);
                    if(j!=string::npos)min=min>s.length()-j-2?s.length()-j-2:min;
                }
            }
        }
    }
        cout << min << "\n";
}
}

