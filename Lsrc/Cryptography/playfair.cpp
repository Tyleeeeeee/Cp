#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

string e,p;
int sr=1,sc=3; // sr sc == 'J'
char k[5][5]={
        'A','B','C','D','E',
        'F','G','H','I','K',
        'L','M','N','O','P',
        'Q','R','S','T','U',
        'V','W','X','Y','Z'
    };
void solve(int i,int j)
{
    pair<int,int> ci,cj;
    ci.first=ci.second=cj.first=cj.second=-1;
    for(int q=0;q<5;++q) for(int w=0;w<5;++w){
        if(k[q][w]==e[i]) ci.first=q,ci.second=w;
        if(k[q][w]==e[j]) cj.first=q,cj.second=w;
    }
    if(ci.first==-1) ci.first=sr,ci.second=sc;
    if(cj.first==-1) cj.first=sr,cj.second=sc;
    if(ci.first==cj.first) ci.second=(ci.second+4)%5,cj.second=(cj.second+4)%5;
    else if(ci.second==cj.second) ci.first=(ci.first+4)%5,cj.first=(cj.first+4)%5;
    else swap(ci.second,cj.second);
    p+=k[ci.first][ci.second]-'A'+'a';
    p+=k[cj.first][cj.second]-'A'+'a';
}
int main()
{
    fast_io;
    e="OWTUUBMHSI";
    for(int q=0;q<e.length();q+=2){
        solve(q,q+1);
    }
    cout << p << "\n";
}

