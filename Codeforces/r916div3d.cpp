#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int t,n;
    long long max;
    cin>>t;
    while(t--&&cin>>n){ pair<long long,int> a[n],b[n],c[n]; max=0;
        for(int q=0;q<n;++q)cin>>a[q].first,a[q].second=q;
        for(int q=0;q<n;++q)cin>>b[q].first,b[q].second=q;
        for(int q=0;q<n;++q)cin>>c[q].first,c[q].second=q;
        sort(a,a+n),sort(b,b+n),sort(c,c+n);
        for(int q=n-1;q>=n-3;--q){
            for(int w=n-1;w>=n-3;--w){
                if(a[q].second==b[w].second) continue;
                for(int e=n-1;e>=n-3;--e){
                    if(a[q].second==c[e].second || b[w].second==c[e].second) continue;
                    else max=max<a[q].first+b[w].first+c[e].first?a[q].first+b[w].first+c[e].first:max;
                }
            }
        }
        cout << max << "\n";
    }
}

