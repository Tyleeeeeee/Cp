#include<iostream>
#include<utility>
#include<cstring>
using namespace std;

int t,m,n;
pair<int,int> arr[50][50];

int solve()
{
    int sum;
    sum=0;
    for(int q=0;q<m;++q){
        for(int w=0;w<n;++w){
            int prm=4;
            if(arr[q][w].first) continue;
            else{
                if(q>0 && !arr[q-1][w].first) prm--;
                if(q<m-1 && !arr[q+1][w].first) prm--;
                if(w>0 && !arr[q][w-1].first) prm--;
                if(w<n-1 && !arr[q][w+1].first) prm--;
            }
            sum+=prm;
        }
    }
    return sum;
}
void dfs(int ans,int q,int w)
{
    if(arr[q][w].first) return;
    if(!arr[q][w].second) arr[q][w].second=ans;
    if(q>0 && !arr[q-1][w].second) dfs(ans,q-1,w);
    if(q<m-1 && !arr[q+1][w].second) dfs(ans,q+1,w);
    if(w>0 && !arr[q][w-1].second) dfs(ans,q,w-1);
    if(w<n-1 && !arr[q][w+1].second) dfs(ans,q,w+1);
    if(q>0 && w>0 && !arr[q-1][w-1].second) dfs(ans,q-1,w-1);
    if(q>0 && w<n-1 && !arr[q-1][w+1].second) dfs(ans,q-1,w+1);
    if(q<m-1 && w>0 && !arr[q+1][w-1].second) dfs(ans,q+1,w-1);
    if(q<m-1 && w<n-1 && !arr[q+1][w+1].second) dfs(ans,q+1,w+1);
    return ;
}
int main()
{
    cin>>t;
    while(t--&&cin>>m>>n){
        int ans;
        ans=1;
        memset(arr,0,sizeof(arr));
        for(int q=0;q<m;++q)
            for(int w=0;w<n;++w)
                cin>>arr[q][w].first;
        for(int q=0;q<m;++q){
            for(int w=0;w<n;++w){
                if(arr[q][w].first || arr[q][w].second) continue;
                else dfs(ans++,q,w);
            }
        }
        cout << --ans << " " << solve() << "\n";
    }
}

