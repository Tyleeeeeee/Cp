#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,m;
    long long Min;
    cin>>t;
    while(t--&&cin>>n>>m){long long arr[2][n]; Min=1e18;
        for(int q=0;q<2;++q) for(int w=0;w<n;++w) cin>>arr[q][w];
        for(int w=n-2;w>=0;--w){
            arr[0][w]=min(arr[0][w+1],arr[1][w+1])+arr[0][w];
            arr[1][w]=min(arr[0][w+1],arr[1][w+1])+arr[1][w];
            if(w<=m-1){
                Min=min(Min,arr[0][w]);
            }
        }
        if(n==m) Min=min(Min,arr[0][n-1]);
        cout << Min << "\n";
    }
}

