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

ll n;
double w,res;
int main()
{
    fast_io;
    cin>>n>>w;
    vector<double> arr(2*n); for(auto&v:arr)cin>>v;
    sort(arr.begin(),arr.end());
    if(arr[0]*2<=arr[n]) res=(arr[0] + arr[0]*2)*n;
    else res=(arr[n] + arr[n]/2)*n;
    cout << fixed << setprecision(12) << (res<=w?res:w) << "\n";
}
/*
   author :tlx
               */

