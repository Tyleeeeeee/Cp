#include<iostream>
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

int n,res,cur;
string s,solve;
map<int,int> mp;
int main()
{
    fast_io;
    cin>>n>>s;
    res=cur=0;
    mp[0]=-1;
    for(int q=0;q<n;++q){
        cur+=(s[q]-'0')?1:-1;
        if(mp.find(cur)==mp.end()) mp[cur]=q;
        else{
            res=max(res,q-mp[cur]);
        }
    }
    cout << res << "\n";
}

