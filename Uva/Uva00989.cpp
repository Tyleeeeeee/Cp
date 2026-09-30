#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<vector<int> > &sudoku,int i,int j,int val)
{
    for(int q=0;q<9;++q)
    {
        if(sudoku[i][q]==val) return false;
        if(sudoku[q][j]==val) return false;
    }
    int boxrow=i/3,boxcol=j/3;
    boxrow*=3; boxcol*=3;
    for(int q=boxrow;q<boxrow+3;++q)
    {
        for(int p=boxcol;p<boxcol+3;++p)
        {
            if(sudoku[q][p]==val) return false;
        }
    }
    return true;
}
bool solvesudoku(vector<vector<int> > &sudoku,int row,int col)
{
    if(row==8 && col==9) return true;
    if(col==9)
    {
        col=0;
        row++;
    }
    if(sudoku[row][col]) return solvesudoku(sudoku,row,col+1);
    for(int num=1;num<10;++num)
    {
        if(issafe(sudoku,row,col,num))
        {
            sudoku[row][col]=num;
            if(solvesudoku(sudoku,row,col+1)) return true;
        }
        sudoku[row][col]=0;
    }
    return false;
}

int main()
{
    int t;
    while(cin >> t)
    {
        while(t--)
        {
            vector<vector<int> > sudoku(9,vector<int>(9));
            for(int i=0;i<9;++i) for(int j=0;j<9;++j) cin >> sudoku[i][j];
            solvesudoku(sudoku,0,0);
            for(int i=0;i<9;++i)
            {
                for(int j=0;j<9;++j)
                {
                    if(!j) cout << sudoku[i][j];
                    else cout << " " << sudoku[i][j];
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
}