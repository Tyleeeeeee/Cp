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

ll res,arr[702];
string s;
int main()
{
    fast_io;
    cin>>s;
    res=0;
    memset(arr,0,sizeof(arr));
    for(char x:s){
        for(int q=0;q<26;++q){
            //very classic algorithm for subsequence count
            arr[q*26+26+x-'a']+=arr[q];
        }
        arr[x-'a']++;
    }
    cout << *max_element(arr,arr+702) << "\n";
}
/*
   author :tlx
               */

