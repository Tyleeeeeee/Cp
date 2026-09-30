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
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl1=1e9+7;
const ll mdl2=998244353;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)
#define MAX 1000001 //1e6+1
#define pb(x) push_back(x)

ll n;
vector<int> dp;
int main()
{
    fast_io;
    ll tmp;
    cin>>n;
    for(int q=0;q<n;++q){
        cin>>tmp;
        if(!dp.size()) dp.pb(tmp);
        else{
            if(tmp>dp[dp.size()-1]) dp.pb(tmp);
            else *lower_bound(dp.begin(),dp.end(),tmp)=tmp;
        }
    }//LIS
    cout << dp.size() << "\n";
}
/*
   author :tlx
               */

