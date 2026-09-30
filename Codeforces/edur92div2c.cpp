#include<iostream>
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
#include<stack>
using namespace std;
using ll=long long;
const ll mdl=1e9+7;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll t,res;
string s;
ll solve(ll q,ll w){
    int l;
    l=0;
    for(char x:s){
        if(x-'0'==q) l++,swap(q,w);
    }
    if(q!=w && l&1) l--;
    return l;
}
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>s){
        res=0;
        for(int q=0;q<10;++q)
            for(int w=0;w<10;++w)
                res=max(res,solve(q,w));
        cout << s.length()-res << "\n";
    }
}
/*
   author :tlx
               */

