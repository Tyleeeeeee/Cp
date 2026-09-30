#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,ans,a,b;
    string s;
    cin>>t;
    while(t--&&cin>>a>>b>>s){ans=a;
        int i=s.find('1'),j=s.rfind('1');
        if(i==string::npos) ans=0;
        else{
            for(int q=i,zero=0;q<=j;++q){
               if(s[q]=='0') zero++;
               else if(zero && s[q]=='1'){
                   ans+=(zero*b<a?zero*b:a),zero=0;
               }
            }
        }
        cout << ans << "\n";
    }
}

