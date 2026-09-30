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
void storesum(int sum,triplet *ans,int *cct,int r,int c);
int main()
{
    fast_io;
    int n,m,counter,tmp;
    triplet arr[100],multi[100];
    cin>>n>>m;
    counter=0;
    for(int q=0;q<n;++q)
        for(int w=0;w<m;++w){
            cin>>tmp;
            if(tmp) arr[counter].val=tmp,arr[counter].row=q,arr[counter++].col=w;
        }
    int cnt=0;
    cin>>n>>m;
    for(int q=0;q<n;++q)
        for(int w=0;w<m;++w){
            cin>>tmp;
            if(tmp) multi[cnt].val=tmp,multi[cnt].row=q,multi[cnt++].col=w;
        }
    cout << "---" << "\n";
    for(int q=0;q<counter;++q) cout << arr[q].row << " " << arr[q].col << " " << arr[q].val << "\n";
    cout << "---" << "\n";
    for(int q=0;q<cnt;++q)cout << multi[q].row << " " << multi[q].col << " " << multi[q].val << "\n";
    cout << "---" << "\n";
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
    cout << "---" << "\n";
    int cct,sum;
    triplet ans[100];
    cct=0; memset(ans,0,sizeof(ans));
    for(int q=0;q<cnt;++q){
        sum=0;
        for(int w=0;w<counter;++w){
            if(multi[q].col==transp[w].col) sum+=multi[q].val*transp[w].val;
            storesum(sum,ans,&cct,multi[q].row,transp[w].row);
            sum=0;
        }
    }
        
    for(int q=0;q<cct;++q)cout << ans[q].row << " " << ans[q].col << " " << ans[q].val << "\n";
}
void storesum(int sum,triplet *ans,int *cct,int r,int c){
    if(!sum) return;
    int ok=1;
    for(int q=0;q<*cct && ok;++q) if(ans[q].row==r && ans[q].col==c) ans[q].val+=sum,ok=0;
    if(ok) ans[*cct].val+=sum,ans[*cct].row=r,ans[(*cct)++].col=c;
}

