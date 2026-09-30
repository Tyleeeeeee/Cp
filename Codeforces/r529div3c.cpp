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

ll n,k;
int main()
{
    fast_io;
    cin>>n>>k;
    list<ll> que;
    vector<ll> ans;
    ll tmp,cnt,res;
    tmp=n,cnt=0,res=1;
    while(tmp)cnt+=tmp&1,tmp>>=1;
    if(k<cnt || k>n) res=0;
    else{
        for(int q=0;q<33 && cnt;++q) if(n&(1<<q)) que.push_back(n&(1<<q)),cnt--,k--;
        while(k){
            ll x=que.front();
            que.pop_front();
            if(x==1) ans.push_back(x);
            else{
                for(int q=0;q<2;++q) que.push_back(x/2);
                k--;
            }
        }
    }
    while(que.size()) ans.push_back(que.front()),que.pop_front();
    cout << (res?"YES":"NO") << "\n";
    if(res) {
        for(auto&v:ans)cout << v << " " ;
        cout << "\n";
    }
}

