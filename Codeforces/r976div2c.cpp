#include<iostream>
using namespace std;
using ll=long long;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    ll t,b,c,d;
    cin>>t;
    while(t--&&cin>>b>>c>>d){
        ll ans,lsbd,sft;
        sft=ans=0;
        while(d || b || c){
            lsbd=d&0b1;
            if(lsbd){
                if((b&0b1)==0 && (c&0b1)==1){ans=-1; break;}
                if((b&0b1)==(c&0b1)){ans+=((0b1-b&0b1)<<sft),sft++;}
                else ans+=((b&0b1)<<sft),sft++;
            }
            else{
                if((b&0b1)==1 && (c&0b1)==0){ans=-1; break;}
                if((b&0b1)==(c&0b1)){ans+=((b&0b1)<<sft),sft++;}
                else ans+=((c&0b1)<<sft),sft++;
            }
            d>>=1,b>>=1,c>>=1; 
        }
        cout << ans << "\n";
    }
}





