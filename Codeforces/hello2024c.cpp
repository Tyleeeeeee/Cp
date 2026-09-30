#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,ans,dup;
    cin>>t;
    while(t--&&cin>>n){ dup=ans=0;
        int arr[n];
        for(int q=0;q<n;++q){
            cin>>arr[q];
            if(q>0 && arr[q]==arr[q-1]) dup++;
        }
        if(n>2 && dup<n-1){
            vector<long long> a(1,1e18),b(1,1e18);
            for(int q=0;q<n;++q){
                long long x,y;
                x=a[a.size()-1],y=b[b.size()-1];
                if(arr[q]>x && arr[q]>y){
                    if(x>y) b.push_back(arr[q]);
                    else a.push_back(arr[q]);
                }
                else if(arr[q]>x && arr[q]<=y) b.push_back(arr[q]);
                else if(arr[q]<=x && arr[q]>y) a.push_back(arr[q]);
                else if(x>y) b.push_back(arr[q]);
                else a.push_back(arr[q]);
            }
            for(int q=0;q+1<a.size();++q) if(a[q]<a[q+1]) ans++;
            for(int q=0;q+1<b.size();++q) if(b[q]<b[q+1]) ans++;
        }
        cout << ans << "\n";
    }
}

