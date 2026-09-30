#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
const ll mx=1e18;

ll t,s,sum,res;
string n;
int main()
{
    fast_io;
    cin>>t;
    while(t-- && cin>>n>>s){
        sum=0;
        for(char x:n)sum+=(x-'0');
        if(sum<=s) res=0;
        else{
            ll ok=1;
            res=sum=0;
            for(char x:n){
                sum+=(x-'0');
                if(!ok) res*=10;
                else if(sum>=s) res=(res+1)*10,ok=0;
                else res=res*10+(x-'0');
            }
            res-=stoll(n);
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

