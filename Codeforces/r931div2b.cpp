#include<iostream>
using namespace std;

int main()
{
    int t,ans;
    long long n;
    cin>>t;
    while(t--&&cin>>n){ ans=0x16161616;
        for(int q=0;q<3;++q){
            for(int w=0;w<2;++w){
                for(int e=0;e<5;++e){
                    for(int r=0;r<3;++r){long long sum=q+w*3+e*6+r*10;
                        if(sum<=n && (n-sum)%15==0) ans=ans>q+w+e+r+(n-sum)/15?q+w+e+r+(n-sum)/15:ans;
                    }
                }
            }
        } 
        cout << ans << "\n";
    }
}

