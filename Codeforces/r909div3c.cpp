#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int t,n,Max,tmp,pre,cur,min;
    cin>>t;
    while(t-- && cin>>n)
    {
        Max=min=-0x16161616;
        cur=0;
        for(int q=0;q<n;++q)
        {
            cin>>tmp,min=tmp>min?tmp:min;
            cur+=tmp;
            if(!q) cur=cur>0?cur:0;
            else cur=cur>0 && abs(tmp%2)!=abs(pre%2)?cur:(cur<=0?0:(tmp>0)?tmp:0);
            Max=cur>Max?cur:Max;
            pre=tmp;
        }
        if(!Max) Max=min;
        cout << Max << "\n";
    }
}

