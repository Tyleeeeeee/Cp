#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    long long a,b,e,o,fl;
    cin>>t;
    while(t--&&cin>>n)
    {
        fl=e=o=a=b=0;
        long long arr[n];
        for(auto&v:arr)cin>>v,o+=v%2,e+=!(v%2);
        if(n==1) cout << (arr[0]%2?"Tie":"Alice") << "\n";
        else if(o==n) cout << "Bob\n";
        else if(e==n) cout << "Alice\n";
        else{
            sort(arr,arr+n);
            for(int q=n-1;q>=0;--q){
                if(!fl){
                    a+=arr[q]%2==0?arr[q]:0;
                    fl=1;
                }
                else{
                    b+=arr[q]%2?arr[q]:0;
                    fl=0;
                }
            }
            cout << (a>b?"Alice":a==b?"Tie":"Bob") << "\n";
        }
    }
}

