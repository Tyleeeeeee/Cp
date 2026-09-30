#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
#include<list>
#include<map>
#include<set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,n,m,a[2][400001];
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>m){
        for(int q=0;q<2;++q) for(int w=0;w<n+m+1;++w) cin>>a[q][w];
        ll pro,tst,cla[n+m+1],c,d;
        c=d=pro=tst=0,n++;
        for(int q=0;q<n+m;++q){
            if((a[0][q]>a[1][q] && c<n)|| d==m) pro+=a[0][q],cla[q]=0,c++;
            else pro+=a[1][q],cla[q]=1,d++;
        }
        n--,m++,c=d=0;
        for(int q=0;q<n+m;++q){
            if((a[0][q]>a[1][q] && c<n)|| d==m) tst+=a[0][q],cla[q]=0,c++;
            else tst+=a[1][q],cla[q]=1,d++;
        }
        for(int q=0;q<n+m;++q) cout << (cla[q]?tst-a[1][q]:pro-a[0][q]) << " ";
        cout << "\n";
    }
}

/*
   author :tlx
               */







