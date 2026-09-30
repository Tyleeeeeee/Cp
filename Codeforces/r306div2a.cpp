#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int main()
{
    fast_io;
    int ok;
    string s,f[2]={"AB","BA"};
    cin>>s;
    ok=0;
    for(int q=0;q<2;++q){
        int pos=0;
        if((pos=s.find(f[q],pos))!=string::npos) pos=s.find(f[q^1],pos+2);
        if(pos!=string::npos) ok=1;
    }
    cout << (ok?"YES":"NO") << "\n";
}

