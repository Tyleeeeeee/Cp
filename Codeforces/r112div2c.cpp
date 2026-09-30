#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int t,m;
    long long arr[2][100000],ans;
    cin>>t;
    while(t--&&cin>>m){ ans=1e18;
        for(int q=0;q<2;++q){
            for(int w=0;w<m;++w){
                cin>>arr[q][w];
                if(w>0) arr[q][w]+=arr[q][w-1];
            }
        }
        for(int q=0;q<m;++q){
            ans=min(ans,max(arr[0][m-1]-arr[0][q],(q>0?arr[1][q-1]:0)));
        }
        cout << ans << "\n";
    }
}

