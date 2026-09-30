#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--&&cin>>n){ pair<int,int> ab[n];
        for(int q=0;q<n;++q)cin>>ab[q].first;
        for(int q=0;q<n;++q)cin>>ab[q].second;
        sort(ab,ab+n);
        for(int q=0;q<n;++q){
            if(!q) cout << ab[q].first;
            else cout << " " << ab[q].first;
        }
        cout << "\n";
        for(int q=0;q<n;++q){
            if(!q)cout << ab[q].second;
            else cout << " " << ab[q].second;
        }
        cout << "\n";
    }
}

