#include<iostream>
#include<fstream>
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
#include<set>
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,res;
string s;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>s){
        ll sum;
        map<ll,ll> mp;
        mp[0]=1;
        sum=res=0;
        for(int q=0;q<n;++q){
            sum+=s[q]-'1';
            res+=(mp[sum]++);
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */



