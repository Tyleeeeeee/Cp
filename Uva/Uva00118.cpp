#include<iostream>
#include<string>
#include<vector>
using namespace std;

class coordinate{
    public:
    int r;
    int c;
    int dir;
    int alive=1;
    coordinate(int X,int Y,int Dir):r(X),c(Y),dir(Dir){}
    void turn(char ch)
    {
        if(ch=='R')
        {
            if(dir==8) dir>>=3;
            else dir<<=1;
        }
        else{
            if(dir==1) dir<<=3;
            else dir>>=1;
        }
    }
    bool move(vector<vector<int> > &mp)
    {
        if(r==0 && dir==4)
        {
            if(mp[r][c]){mp[r][c]=0; alive=0; return false;}
            else return true;
        }
        if(r==mp.size()-1 && dir==1)
        {
            if(mp[r][c]){mp[r][c]=0; alive=0; return false;}
            else return true;
        }
        if(c==0 && dir==8)
        {
            if(mp[r][c]){mp[r][c]=0; alive=0; return false;}
            else return true;
        }
        if(c==mp[r].size()-1 && dir==2)
        {
            if(mp[r][c]){mp[r][c]=0; alive=0; return false;}
            else return true;
        }
        if(dir==1) r++;
        else if(dir==2) c++;
        else if(dir==4) r--;
        else if(dir==8) c--;
        return true;
    }
};
int main()
{
    auto direc=[](int ch)
    {
        if(ch==1) return 'N';
        else if(ch==2) return 'E';
        else if(ch==4) return 'S';
        else return 'W';
    };
    int alive;
    int row,col;
    int sr,sc,dir;  
    char d;
    string s;
    cin >> col >> row;
    vector<vector<int> > mp(row+1,vector<int>(col+1,1));
    while(cin >> sc >> sr >> d >> s)
    {
        if(d=='N')dir=1;
        else if(d=='S')dir=4;
        else if(d=='E')dir=2;
        else if(d=='W')dir=8;
        coordinate ans(sr,sc,dir);
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='F') 
            {
                if(!ans.move(mp)) {cout << ans.c << " " << ans.r << " "<< direc(ans.dir) << " LOST\n"; break;
            } 
}            else {ans.turn(s[i]);}
            // cout << ans.c << " " << ans.r << " " << direc(ans.dir) << "\n";
        }
        if(ans.alive) cout << ans.c << " " << ans.r << " " << direc(ans.dir) << "\n";
    }
}

