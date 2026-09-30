#include<iostream>
using namespace std;

int main()
{
    long long t,x,ans;
    cin>>t;
    while(t--&&cin>>x){ ans=0;
        if(x>1099) ans=1;
        else{
            for(int q=0;q<10;++q){
                for(int w=0;w<100;++w){
                    if(q*111+w*11==x) {ans=1; break;}
                }
            }
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}

