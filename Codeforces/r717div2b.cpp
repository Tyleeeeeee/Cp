#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int t,n,dp[2000][2000];
int main()
{
    fast_io;
    int res,ans;
    cin>>t;
    while(t--&&cin>>n){
        res=0;
        vector<int> arr(n);
        for(auto&v:arr)cin>>v,res^=v;
        if(!res) ans=1;
        else{
            partial_sum(arr.begin(),arr.end(),arr.begin(),[](int a,int b){return a^b;});
            int ok=0;
            for(int q=0;q<n;++q){
                for(int w=q+1;w<n;++w){
                    if(arr[q]==res && (arr[w]^arr[q])==res && (res^arr[w])==res) {ok=1; break;}
                }
            }
            ans=ok;
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}

