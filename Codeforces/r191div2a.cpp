#include<iostream>
using namespace std;

int main()
{
    int n,tmp,cur,max,on;
    on=cur=max=0;
    cin>>n;
    for(int q=0;q<n;++q)
    {
        cin>>tmp;
        if(tmp){tmp=-1;on++;}
        else tmp=1;
        cur+=tmp;
        cur=cur>0?cur:0;
        max=max>cur?max:cur;
    }
    if(on==n) on--;
    cout << max+on << "\n";
}

