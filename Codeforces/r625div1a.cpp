#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    long long n,arr[800000],tmp,ans;
    cin>>n;
    ans=0;
    memset(arr,0,sizeof(arr));
    for(int q=0;q<n;++q){long long buf;
        cin>>tmp;
        buf=tmp;
        tmp=q+1-tmp;
        arr[tmp>=0?tmp:-1*tmp+400000]+=buf;
        ans=max(ans,arr[tmp>=0?tmp:-1*tmp+400000]);
    }
    cout << ans << "\n";
}

