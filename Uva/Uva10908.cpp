#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<char> > &sq,int mr,int mc)
{
    int i,j,st;
    int N=0;
    while(true)
    {
        st=1;
        if(!(mr>N-1) || !(mc>N-1) || !(mr<sq.size()-N) || !(mc<sq[mr].size()-N)) break;
        for(i=mr-N,j=mc-N;i<=mr+N && j<=mc+N;)
        {
            if(sq[i][mc-N]!=sq[mr][mc]){st=0;break;}
            if(sq[i][mc+N]!=sq[mr][mc]){st=0;break;}  
            if(sq[mr-N][j]!=sq[mr][mc]){st=0;break;}
            if(sq[mr+N][j]!=sq[mr][mc]){st=0;break;}
            j++;
            i++;
        }
        if(st) N++;
        else break ;
    }
    return (N-1)*2+1;
}
int main()
{
    int t,rw,cl,c,mr,mc;
    while(cin>>t)
    {
        while(t-- && cin>>rw>>cl>>c)
        {
            cin.get();
            vector<vector<char> > sq(rw,vector<char>(cl));
            for(int i=0;i<rw;++i)for(int j=0;j<cl;++j)cin>>sq[i][j];
            cout << rw << " " << cl << " " << c << "\n";
            for(int i=0;i<c;++i)
            {
                cin>>mr>>mc;
                cout << solve(sq,mr,mc) << "\n";
            }
        }
    }
}

