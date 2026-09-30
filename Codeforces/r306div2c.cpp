#include<iostream>
#include<string>
using namespace std;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    int ok;
    string s,ans;
    cin>>s;
    ok=0;
    int i=s.find('8'),j=s.find('0');
    if(i!=string::npos || j!=string::npos) ans+=(i!=string::npos?'8':'0'),ok=1;
    else{
        for(int q=s.length()-1;q>=0 && !ok;--q){
            for(int w=q-1;w>=0 && !ok;--w){
                int sum=s[q]-'0'+2*(s[w]-'0');
                if(sum%8==0) {ans+=s[w],ans+=s[q],ok=1;}
                for(int e=w-1;e>=0 && !ok;--e){
                    sum+=4*(s[e]-'0');
                    if(sum%8==0) {ans+=s[e],ans+=s[w],ans+=s[q],ok=1;}
                }
            }
        }
    }
    if(ok) cout << "YES\n" << ans << "\n";
    else cout << "NO\n";
}


