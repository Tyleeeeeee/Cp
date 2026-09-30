#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
using ll=long long;
#define fast_io cin.tie(0),ios::sync_with_stdio(false)

int arr[200*200+1];
int main()
{
    fast_io;
    int t,n,m;
    cin>>t;
    while(t--&&cin>>n>>m){
        memset(arr,0,sizeof(arr));
        for(int q=0;q<n*m;++q)cin>>arr[q];
        #define pt(i,j) (arr[(i)*m+(j)])
        int R[n],C[m],ok=0;
        //<p = 1 ,>=p = 0
        for(int p=0;p<=n*m && !ok;++p){
            for(R[0]=0;R[0]<=1;++R[0]){//q<p 1 -> 0 0 -> 1 
                for(int k=0;k<m;++k) C[k]=pt(0,k)^R[0]^(k<p);
                for(int k=1;k<n;++k) R[k]=pt(k,0)^C[0]^(k*m<p);
                int srt=1;
                for(int k=0;k<n*m;++k){ int i=k/m,j=k%m;
                    if(pt(i,j)^C[j]^R[i]^(k<p)){srt=0; break;}
                }
                if(srt) {ok=1; break;}
            }
        }
        cout << (ok?"YES":"NO") << "\n";
    }
}

