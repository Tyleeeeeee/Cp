#include<iostream>
using namespace std;

int main()
{
    int t,m,mx,n;
    string s,l,r;
    cin>>t;
    while(t--&&cin>>s>>m>>l>>r){ mx=0;
        n=s.length();
        for(int q=0;q<m;++q){
            int nmx=mx;
            for(int w=l[q]-'0';w<=r[q]-'0';++w){
                int cur=mx;
                while(cur<n && s[cur]-'0'!=w) cur++;
                nmx=max(nmx,cur);
            }
            mx=nmx+1;
        }
        cout << (mx>n?"YES":"NO") << "\n";
    }
}

