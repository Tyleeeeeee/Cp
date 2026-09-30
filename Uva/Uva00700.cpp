#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<vector<int> > cp,int nocp,int y)
{
    int n=1;
    while(cp[nocp][0]<10000)
    {
        if(cp[nocp][0]==y) return true;
        cp[nocp][0]+=cp[nocp][2]-cp[nocp][1];
    }
    return false;
}
bool solve(vector<vector<int> > &cp,int nocp,int y)
{
    if(nocp==cp.size()) return true;
    if(isvalid(cp,nocp,y))
    {
        if(solve(cp,nocp+1,y)) return true;
    }
    return false;
}
int main()
{
    int n,y,counter=0,ans;
    while(cin >> n && n)
    {
        ans=0;
        vector<vector<int> > cp(n,vector<int>(3));
        for(int i=0;i<n;++i)
        {
            cin >> cp[i][0] >> cp[i][1] >> cp[i][2];
        }
        y=cp[0][0];
        while(y<10000)
        {
            if(solve(cp,0,y)){ans=1; break;}
            y+=cp[0][2]-cp[0][1];
        }
        cout << "Case #" << ++counter << ":\n";
        if(ans) cout << "The actual year is " << y << ".\n\n";
        else cout << "Unknown bugs detected.\n\n";
    }
}

