#include<iostream>
using namespace std;

int main()
{
    int t,n,m,k;
    cin>>t;
    while(t--&&cin>>n>>m>>k){
        for(int q=n;q>m;--q) cout << q << " ";
        for(int q=1;q<=m;++q) cout << q << " ";
        cout << "\n";
    }
}

