#include<iostream>
using namespace std;

int main()
{
    int n,a,b,c,max=0;
    cin>>n>>a>>b>>c;
    for(int q=0;q<=n/a;++q){
        for(int w=0;w<=n/b;++w){
            int sum=q*a+w*b;
            if(sum<=n && (n-sum)%c==0) max=max<q+w+(n-sum)/c?q+w+(n-sum)/c:max;
        }
    }
    cout << max << "\n";
}

