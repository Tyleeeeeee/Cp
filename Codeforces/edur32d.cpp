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
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll n,k,C[1001][1001],res;
int main()
{
    fast_io;
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int q=1;q<1001;++q){
        for(int w=0;w<=q;++w){
            C[q][w]=(!w||q==w)?1:C[q-1][w]+C[q-1][w-1];
        }
    }
    cin>>n>>k;
    //nCn-k * (9/2) + 1
    res=0;
    for(int q=n-k;q<n-1;++q){
        res+=C[n][q]*(k>3?9:k>2?2:1),k--;
    }
    res++;
    cout << res << "\n";
}
/*
   author :tlx
               */





