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
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int t,n,res;
int main()
{
    fast_io;
    cin>>t;
    while(t--&&cin>>n){
        res=0;
        for(int q=0;q<n-3;++q){
            res^=q;
            cout << q << " ";
        }
        res^=(1<<28)^(1<<29);
        cout << (1<<28) << " " << (1<<29) << " " << res << "\n";
    }
}
/*
   author :tlx
               */

