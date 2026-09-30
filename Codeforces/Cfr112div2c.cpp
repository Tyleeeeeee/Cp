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
#include<unordered_set>
#include<stack>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const ll mdl=1e9+7;
const ll inf=0x7FFFFFFFFFFFFFFF;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

ll k,res,pref[1000001];
string s;
int main()
{
    fast_io;
    cin>>k>>s;
    memset(pref,0,sizeof(pref));
    ll cnt,r;
    cnt=r=res=0;
    for(char x:s){
        if(!(x-'0')) r++;
        else pref[cnt++]=r,r=0;
    }
    if(k>cnt) res=0;
    else{
        if(r) pref[cnt++]=r;
        for(int q=0;q+k<=(!r && k?cnt:cnt-1);++q) res+=(pref[q]+(k!=0))*(pref[q+k]+1)/(!k?2:1);
    }
    cout << res << "\n";
}
/*
   author :tlx
               */



