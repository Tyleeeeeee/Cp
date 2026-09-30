#include<iostream>
#include<vector>
using namespace std;

bool dfs(int sr,int sc,int fr,int fc,int cp,int wp,vector<vector<int> > &maze,const function<int(int,int)> &ver)
{
    maze[sr][sc]=0;
    if(sr==fr && sc==fc && cp==wp){cout << ver(sr,sc) << " "; return true; }

    if(sr>0 && maze[sr-1][sc] && dfs(sr-1,sc,fr,fc,cp+1,wp,maze,ver)) {cout << ver(sr,sc) << " "; return true; }
    if(sr<maze.size()-1 && maze[sr+1][sc] && dfs(sr+1,sc,fr,fc,cp+1,wp,maze,ver)){cout << ver(sr,sc) << " "; return true; }
    if(sc>0 && maze[sr][sc-1] && dfs(sr,sc-1,fr,fc,cp+1,wp,maze,ver)){cout << ver(sr,sc) << " "; return true; }
    if(sc<maze[sr].size()-1 && maze[sr][sc+1] && dfs(sr,sc+1,fr,fc,cp+1,wp,maze,ver)){cout << ver(sr,sc) << " "; return true; }

    maze[sr][sc]=1;
    return false;
}

int main()
{
    int row,col,winpath=0;
    cin >> row >> col ;
    vector<vector<int> > maze(row,vector<int>(col));
    for(int i=0;i<row;++i) for(int j=0;j<col;++j) {cin >> maze[i][j]; winpath+=maze[i][j]?1:0;}
    dfs(0,0,row-1,col-1,1,winpath,maze,[col](int i,int j){return j+i*col;}); 
}