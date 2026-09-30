#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll solve(ll n,ll d)
{
    if((n%d)==0) return pow(2,(n/d)-1);
    if(n<d) return solve(d,n)+1;
    else return pow(2,n/d)*solve(n%d,d);
}
int main()
{
    fast_io;
    ll a,k,n,d;
    while(cin>>a){
        if(a==1 && cin>>k){
            string s;
            while(k) s.push_back(((k>1?(k&1):0)^1)+'0'),k=(k&1?k-1:k>>1);
            reverse(s.begin(),s.end());
            n=0,d=1;
            for(int q=0;q<s.length();++q){
                if(s[q]=='1') n+=d;
                else swap(n,d);
            }
            cout << n << "/" << d << "\n";
        }
        else{
            ll sum;
            cin>>n>>d;
            //n>d even else odd
            cout << solve(n,d) << "\n";
        }
    }
}

