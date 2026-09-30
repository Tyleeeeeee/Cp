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

ll t,res,a,b;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>a>>b){
        res=b-a;
        //fixed a or b to brute force
        for(int q=b;q<b+b;++q){
            res=min(res,(q|a)-b+1LL);
        }
        for(int q=a;q<=b;++q){
            res=min(res,(q|b)-b+q-a+1LL);
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */





