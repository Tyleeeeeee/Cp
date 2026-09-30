#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int M_A_X=100001;
int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    vector<vector<int>> dvs(M_A_X,vector<int>());
    //O(NlogN)
    for(int q=2;q<M_A_X;++q){
        for(int w=q;w<M_A_X;w+=q){
            dvs[w].push_back(q);
        }
    }
    int d[M_A_X],n,ans;
    cin>>n;
    int arr[n];
    for(auto&v:arr)cin>>v;
    memset(d,0,sizeof(d));
    ans=0;
    for(int x:arr){
        if(x==1) {ans=1; continue;}
        int mx;
        mx=0;
        for(int di:dvs[x]){
            mx=max(mx,d[di]+1);
        }
        for(int di:dvs[x]){
            d[di]=mx;
        }
        ans=max(ans,mx);
    }
    cout << ans << "\n";
}

