#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n,m,tmp;
    set<int> ans;
    cin>>n>>m;
    int arr[n],dp[n+1];
    for(auto&v:arr) cin>>v;
    for(int q=n-1;q>=0;--q)
    {
        ans.insert(arr[q]);
        dp[q+1]=ans.size();
    }
    for(int q=0;q<m;++q)
    {
        cin>>tmp;
        cout << dp[tmp] << "\n";
    }
}

