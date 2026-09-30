#include<iostream>
#include<cstring>
using namespace std;
using ll=long long;

ll dp[200000][2];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,pe,ne;
    cin>>n;
    ll arr[n];
    for(auto&v:arr)cin>>v;
    pe=ne=0;
    memset(dp,0,sizeof(dp));
    pe+=(dp[0][0]=arr[0]>0),ne+=(dp[0][1]=arr[0]<1);
    for(int q=1;q<n;++q){
        if(arr[q]>0){
            dp[q][0]=dp[q-1][0]+1;
            dp[q][1]=dp[q-1][1];
        }
        else{
            dp[q][0]=dp[q-1][1];
            dp[q][1]=dp[q-1][0]+1;
        }
        pe+=dp[q][0],ne+=dp[q][1];
    }
    cout << ne << " " << pe << "\n";
}

