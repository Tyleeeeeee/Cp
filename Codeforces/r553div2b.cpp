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

ll n,m;
int main()
{
    fast_io;
    cin>>n>>m;
    ll res,x,y,ci,cj;
    vector<ll> ans;
    res=0,ci=cj=-1;
    for(int q=0;q<n;++q){
        cin>>x;
        res^=x;
        for(int w=2;w<=m;++w){
            cin>>y;
            if(y!=x) ci=q,cj=w;
        }
    }
    if(res>0 || ci!=-1){
        if(res) for(int q=0;q<n;++q) ans.push_back(1);
        else{
            for(int q=0;q<n;++q)
                if(q!=ci) ans.push_back(1);
                else ans.push_back(cj);
        }
        res=1;
    }
    cout << (res?"TAK":"NIE") << "\n";
    if(res) {for(auto v:ans) cout << v << " "; cout << "\n";}
}
/*
   author :tlx
               */





