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

typedef struct{
    int row;
    int col;
    int val;
} triplet;
int main()
{
    fast_io;
    int n,m,counter,tmp;
    triplet arr[100];
    cin>>n>>m;
    counter=0;
    for(int q=0;q<n;++q)
        for(int w=0;w<m;++w){
            cin>>tmp;
            if(tmp) arr[counter].val=tmp,arr[counter].row=q,arr[counter++].col=w;
        }
    cout << "---" << "\n";
    for(int q=0;q<counter;++q) cout << arr[q].row << " " << arr[q].col << " " << arr[q].val << "\n";
    cout << "---" << "\n";
    cout << "before:\n";
    for(int q=0;q<counter;++q) arr[q].row^=arr[q].col,arr[q].col^=arr[q].row,arr[q].row^=arr[q].col;
    for(int q=0;q<counter;++q) cout << arr[q].row << " " << arr[q].col << " " << arr[q].val << "\n";
    for(int q=0;q<counter;++q) arr[q].row^=arr[q].col,arr[q].col^=arr[q].row,arr[q].row^=arr[q].col;
    cout << "---" << "\n";
    cout << "after" << "\n";
    int fq[m],pos[m];
    triplet transp[counter];
    memset(fq,0,sizeof(fq));
    for(int q=0;q<counter;++q) fq[arr[q].col]++;
    memset(pos,0,sizeof(pos));
    for(int q=1;q<m;++q) pos[q]=pos[q-1]+fq[q-1];
    for(int q=0;q<counter;++q){
        int x=pos[arr[q].col]++;
        transp[x].row=arr[q].col,transp[x].col=arr[q].row,transp[x].val=arr[q].val;
    }
    for(int q=0;q<counter;++q) cout << transp[q].row << " " << transp[q].col << " " << transp[q].val << "\n";
}

