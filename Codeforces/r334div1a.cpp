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

ll n,res;
string s;
int main()
{
    fast_io;
    cin>>n>>s;
    res=1;
    for(int q=0;q+1<n;++q){
        res+=(s[q]!=s[q+1]);
    }
    //if string already alternative then answer=n else if exist one pair 11/00 then answer=(n-1)+1=n and else exist
    //greater than 1 pair of 11/00 then answer=res+2 and we describe it as min(n,res+2)
    cout << min(n,res+2) << "\n";
}
/*
   author :tlx
               */





