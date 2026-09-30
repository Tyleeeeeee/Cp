#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int solve(int n,int m){
    int ans=1;
    while(m){
        if(m%2)ans*=n;
        n=n*n%(32768);
        ans%=32768;
        m/=2;
    }
    return ans;
}
int main()
{
    int n,arr[32768];
    cin>>n;
    memset(arr,0,sizeof(arr));
    for(int q=0;q<n;++q){
        cin>>arr[q];
        if(arr[q]==0 || arr[q]==32768) arr[q]=0;
        else{
            int min=0x16161616;
            for(int w=0;w<=15;++w){
                for(int e=0;e<=15;++e){
                    if(((arr[q]+w)*solve(2,e))%32768==0){min=min<w+e?min:w+e;}
                }
            }
            arr[q]=min;
        }
    }
    for(int q=0;q<n;++q){
        if(!q)cout << arr[q];
        else cout << " " <<arr[q];
    }
    cout << "\n";
}

