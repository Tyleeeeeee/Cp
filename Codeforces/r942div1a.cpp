#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t,n,k,mn;
    cin>>t;
    while(t--&&cin>>n>>k){ 
        vector<ll> arr(n);
        for(auto&v:arr)cin>>v;
        sort(arr.begin(),arr.end(),[](ll a,ll b){return a>b;});
        //special condition if n==1
        ll counter;
        mn=arr[n-1],counter=0;
        while(1){
            if(!arr.size()) {mn+=k/n,k%=n; break;}
            ll last=*(--arr.end());
            if((last-mn)*counter<=k) {
                k-=(last-mn)*counter,counter++,mn=last;
                arr.pop_back();
            }
            else {mn+=k/counter,k%=counter; break;}
        }
         cout << (mn-1)*n + (arr.size()+k) + 1 << "\n";
    }
}

