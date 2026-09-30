#include<climits>
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> > &grid,int sr,int sc,int fr,int fc,int path,int &winpath)
{
    if(sr==fr && sc==fc){if(path<winpath)winpath=path; return;}
    int val=grid[sr][sc];
    path+=val;
    grid[sr][sc]=-1;
    if(sr>0 && grid[sr-1][sc]>=0) dfs(grid,sr-1,sc,fr,fc,path,winpath);
    if(sr<grid.size()-1 && grid[sr+1][sc]>=0) dfs(grid,sr+1,sc,fr,fc,path,winpath);
    if(sc>0 && grid[sr][sc-1]>=0) dfs(grid,sr,sc-1,fr,fc,path,winpath);
    if(sc<grid[sr].size()-1 && grid[sr][sc+1]>=0) dfs(grid,sr,sc+1,fr,fc,path,winpath);
    grid[sr][sc]=val;
    return;
}
int main()
{
    int t,n,ans;
    cin >> t;
    while(t-- && cin >> n)
    {
        ans=INT_MAX;
        vector<vector<int> > grid(n,vector<int>(n));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) cin>>grid[i][j];
        dfs(grid,0,0,n-1,n-1,0,ans);
        cout << ans << "\n";
    }
}

