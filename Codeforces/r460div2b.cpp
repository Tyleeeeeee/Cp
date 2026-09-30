#include<iostream>
#include<vector>
using namespace std;

bool isPerfect(long long N)
{
    int ans=0;
    while(N)
    {
        ans+=N%10;
        N/=10;
    }
    if(ans==10) return true;
    else return false;
}
int main()
{
    int k;
    long long ref=19;
    vector<long long> pn;
    while(pn.size()<10000)
    {
        if(isPerfect(ref)) pn.push_back(ref);
        ref++;
    }
    cin>>k;
    cout << pn[k-1] << "\n";
}

