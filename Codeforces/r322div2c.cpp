#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    int n,k,ans;
    cin>>n>>k;
    ans=0;
    pair<int,int> arr[n];
    for(auto &v:arr){
        cin>>v.second;
        v.first=v.second<100?(v.second/10+1)*10-v.second:0;
    }
    sort(arr,arr+n);
    for(auto &v:arr){
        ans+=(v.second+=(k>=v.first?v.first:k))/10,k-=k>=v.first?v.first:k;
    }
    if(k){
        for(auto &v:arr) 
            if(v.second<100) ans+=(k>=100-v.second?100-v.second:k)/10,k-=k>=100-v.second?100-v.second:k;
    }
    cout << ans << "\n";
}

