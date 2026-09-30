#include<iostream>
#include<utility>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[2*n];
    for(int q=0;q<2*n;++q) arr[q]=q+1;
    if(k!=0) {
        for(int q=0;q<=4*(k-1);q+=4) swap(arr[q],arr[q+1]);
    }
    for(int q=0;q<2*n;++q){
        if(!q) cout << arr[q];
        else cout << " " << arr[q] ;
    }
    cout << "\n";
}

