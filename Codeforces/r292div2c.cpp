#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll=long long ;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    ll n,num;
    string ans;
    cin>>n>>num;
    while(num){
        if(num%10==0 || num%10==1){num/=10; continue;}
        if(num%10==2 || ((num%10)%2) && num%10!=9){ans.push_back((num%10)+'0');}
        else{
            if(num%10==4) ans+="223";
            else if(num%10==6) ans+="35";
            else if(num%10==8) ans+="2227";
            else ans+="2337";
        }
        num/=10;
    }
    sort(ans.begin(),ans.end(),[](char a,char b){return a>b;});
    cout << ans << "\n";
}

