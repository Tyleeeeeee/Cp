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

ll t,n,x;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n>>x){
        ll a,b,c,res;
        res=0;
        //ab+bc+ca<=n a+b+c<=x ->c<=(x-a-b) c<=(n-ab)/(b+a) -> c<=min((x-a-b),(n-ab)/(b+a))
        for(a=1;a<=min(x,n);++a){
            for(b=1;a*b<=n && a+b<=x;++b) //O(nlogn)
                res+=min(x-a-b,(n-a*b)/(b+a));
        }
        cout << res << "\n";
    }
}
/*
   author :tlx
               */

