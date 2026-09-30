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

ll a,b,res;
int main()
{
    fast_io;
    cin>>a>>b;
    if(a==b) res=inf;
    else if(a<b) res=0;
    else{
        res=0;
        for(int q=1;q<=sqrt(a-b);++q){
            if(!((a-b)%q)){
                if(q>b) res++;
                #define A(x) ((x)*(x))
                if(A((a-b)/q)!=(a-b) && (a-b)/q > b) res++;
            }
        }
    }
    if(res==inf) cout << "infinity" << "\n";
    else cout << res << "\n";
}
/*
   author :tlx
               */





