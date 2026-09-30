#include<iostream>
using namespace std;

int main()
{
    int t,n,a,b,c,d;
    cin>>t;
    while(t--&&cin>>n){
        int arr[2][n];
        for(int q=0;q<2;++q) for(int w=0;w<n;++w) cin >> arr[q][w];
        //a=1 1 b= -1 -1 c=first d=second
        a=b=c=d=0;
        for(int q=0;q<n;++q){
            if(arr[0][q]==1 && arr[1][q]==1) a++;
            else if(arr[0][q]==-1 && arr[1][q]==-1) b++;
            else if(arr[0][q]>arr[1][q]) c+=arr[0][q];
            else d+=arr[1][q];
        }
        while(a--){
            if(c>d) d++;
            else c++;
        }
        while(b--){
            if(c>d) c--;
            else d--;
        }
        cout << (c<d?c:d) << "\n";
    }
}

