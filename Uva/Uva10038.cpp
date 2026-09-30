#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,ans,pre,cur;
    while(cin >> n )
    {
        pre=cur=ans=0;
        cin >> cur;
        for(int q=1;q<n;++q)
        {
            pre=cur;
            cin >> cur;
            ans+=abs(cur-pre);
        }
        cout << (ans==(n-1)*(n)/2?"Jolly\n":"Not jolly\n");
    }
}


