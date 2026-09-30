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

string s;
ll n[2][3],a[3],r;
ll solve(){
    ll i,j,mid,res,ok;
    res=i=0,j=1e16;
    while(i<=j){
        mid=(i+j)/2;
        ull cost;
        //0=b 1=s 2=c
        cost=0,ok=1;
        for(int q=0;q<3 && ok;++q) cost+=(n[0][q]-mid*a[q]>=0?0:(mid*a[q]-n[0][q])*n[1][q]),ok=(cost>r?0:1);
        if(cost<=r) {res=max(res,mid),i=mid+1;}
        else j=mid-1;
    }
    return res;
}
int main()
{
    fast_io;
    cin>>s; for(int q=0;q<2;++q) for(int w=0;w<3;++w) cin>>n[q][w]; cin>>r;
    memset(a,0,sizeof(a));
    //0=b 1=s 2=c
    for(char x:s){
        if(x=='B') a[0]++;
        else if(x=='S') a[1]++;
        else a[2]++;
    }
    cout << solve() << "\n";
}
/*
   author :tlx
               */





