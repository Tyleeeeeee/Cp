#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long arr[2][n],min;
    min=1e10;
    for(int q=0;q<2;++q) for(int w=0;w<n;++w) cin >> arr[q][w];
    for(int q=0;q<n;++q){
        int b=-1;
        long long cs=arr[1][q];
        for(int w=0;w<q;++w){
            if(arr[0][w]>=arr[0][q]) continue;
            else if(b==-1 || (b!=-1 && arr[1][b]>arr[1][w])) b=w;
        }
        if(b==-1) continue;
        cs+=arr[1][b];
        b=-1;
        for(int w=q+1;w<n;++w){
            if(arr[0][q]>=arr[0][w]) continue;
            else if(b==-1 || (b!=-1 && arr[1][b]>arr[1][w])) b=w;
        }
        if(b==-1) continue;
        cs+=arr[1][b];
        min=min>cs?cs:min;
    }
    if(min==10000000000) min=-1;
    cout << min << "\n";
}

